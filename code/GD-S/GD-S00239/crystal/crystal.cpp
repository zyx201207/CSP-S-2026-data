#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],s[500005];
bool check(int l,int r){
	long long w=1LL*a[r]*(r-l+1)-(s[r]-s[l-1]);
	if(w<=m)	return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int j=1;
	for(int i=1;i<=n;i++){
		j=max(j,i+1);
		while(j<=n){
			if(check(i,j)==0)	break;
			j++;
		}
		ans=max(ans,(j-1)-i+1);
	}
	cout<<ans;
	return 0;
} 
