#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string st;
ll n,m,a[500005],s[500005],as=1;	
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s[j]-s[i-1]<=m){
				as=max(as,ll(j-i+1));
			}
		}
	}
	cout<<as;
	return 0;
}
