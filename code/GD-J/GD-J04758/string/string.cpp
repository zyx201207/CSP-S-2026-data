#include<bits/stdc++.h>
using namespace std;
struct zf{
	long long gs;
	char s;
}a[200001];
int n;
long long sum,ans=0;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].gs>>a[i].s;
		sum+=a[i].gs;
	}
	int d=(sum+1)/2;
	int zx=0;
	for(int i=1;i<=n;i++){
		if(d>a[i].gs)d-=a[i].gs;
		else{
			zx=i;
			break;
		}
	}
	if(sum%2==1){
		a[zx].gs--;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].s!=a[r].s)ans+=min(a[l].gs,a[r].gs);
		if(a[l].gs<a[r].gs)a[r].gs-=a[l].gs,l++;
		else if(a[l].gs>a[r].gs) a[l].gs-=a[r].gs,r--;
		else l++,r--;
	}
	cout<<ans;
	return 0;
}
