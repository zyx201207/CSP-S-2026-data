#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],l,r,maxn=0-1e13,sum,p,k;
     
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    l=r=1,p=0;
    while(r<n||l<n){
		if(p<=m)maxn=max(maxn,k);
		if(p<=m&&r!=n){
			r++;
			p=p+(++k)*(a[r]-a[r-1]);
		}
		else{
			p=p-(a[r]-a[l++]);
			k--;
		}
	}
	cout<<maxn+1<<endl;
    return 0;
}
