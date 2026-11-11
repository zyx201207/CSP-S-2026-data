#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s[200005],ans[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>0;i--){
		s[a[i]]=(s[a[i]]+1)%2;
		for(int j=1;j<=m;j++){
			ans[j]+=s[j];
			cout<<s[j]<<' ';
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
