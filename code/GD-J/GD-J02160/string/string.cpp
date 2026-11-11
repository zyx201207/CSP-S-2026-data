#include<bits/stdc++.h>
using namespace std;
long long n,a[200010]={0},sum=0,lc=0,rc,lch=0,rch=0,k;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	rc=n+1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(lc<rc){
		if(lch<=0){
			lc++;
			lch=a[lc];
		}
		if(rch<=0){
			rc--;
			rch=a[rc];
		}
		if(lc>=rc)break;
		if(c[lc]!=c[rc])sum+=min(lch,rch);
		k=lch;
		lch-=rch;
		rch-=k;
	}
	cout<<sum;
	return 0;
}
