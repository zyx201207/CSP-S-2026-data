#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],mi=0;
string c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(true){
		if(l>=r){
			break;
		}
		int mi1=min(a[l],a[r]);
		if(c[l]!=c[r]){
			mi+=mi1;
			a[l]-=mi1;
			a[r]-=mi1;
		}
		else{
			a[l]-=mi1;
			a[r]-=mi1;
		}
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--;
	}
	cout<<mi;
	return 0;
}
