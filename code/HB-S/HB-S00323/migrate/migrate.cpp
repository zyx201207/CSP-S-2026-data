#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int a[2000009];
signed main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(a,0x3f,sizeof a);
		int n,d;
		cin>>n>>d;
		int cnt=0,kua=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=3;i<=n;i++){
			if(a[i-2]+d>=a[i]&&a[i-2]+d<a[i+1])kua++;
			if(a[i-1]+d<a[i])kua=0;
			if(kua==2)cnt++;
			cout<<kua<<' ';
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
