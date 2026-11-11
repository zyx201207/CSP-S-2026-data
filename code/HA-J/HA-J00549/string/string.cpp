#include<bits/stdc++.h>
using namespace std;
struct va{
	long long s;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
	}
	long long sum=0;
	int l=1,r=n;
	while(1){
		if(r<=l){
			break;
		}
		if(a[l].c!=a[r].c){
			sum+=min(a[l].s,a[r].s);	
		}
		if(a[l].s>a[r].s){
			a[l].s-=a[r].s;
			r--;
		}else{
			a[r].s-=a[l].s;
			l++;
		}
	}
	cout<<sum;
	return 0;
}
