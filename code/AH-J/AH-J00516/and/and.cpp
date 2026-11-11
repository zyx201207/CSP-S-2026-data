#include<bits/stdc++.h>
using namespace std;
long long maxans,n,m,a[200005],s[35];
bool b[35];
long long space(int x){
	long long xs=1;
	for(int i=1;i<=x;i++)
		xs*=2;
	return xs;	
}
void dfs(long long dep,long long ans){
	if(dep>m){
		maxans=max(maxans,ans);
	}
	long long x1=0,x2=ans;
	for(int i=1;i<=n;i++){
		if(b[i]){
			for(int j=30;j>=0;j--){
				if(a[i]>=s[j]&&ans>=s[j]){
					x1+=s[j];
					a[i]-=s[j];
					ans-=s[j];
				}
				b[i]=false;
				dfs(dep+1,x1);
				b[i]=true;
				ans=x2;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=31;i++){
		s[i]=space(i);
	}
	for(int i=1;i<=35;i++){
		b[i]=true;
	}
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++){
	dfs(1,a[i]);}
	cout<<maxans;
	return 0;
}
