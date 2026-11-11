#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500030],x=1e12,l,p=1,ans,w;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	x=min(x,a[i]);
}sort(a+1,a+1+n);
for(int i=x;i<=1e12;i++){
	int sum=0;
	w=m;
	if(w+a[p]>=i){
		w=w+a[p]-i;
		sum++;
	}l=p-1;
	while(l>=1){
		if(w+a[l]>=i){
			w=w+a[p]-i;
			sum++;
		}else
		break;
		l--;
	}while(a[p+1]<=i+1)
	p++;
	if(ans<=sum){
	ans=sum;
}
	else
	break;
}cout<<ans;
return 0;
}
