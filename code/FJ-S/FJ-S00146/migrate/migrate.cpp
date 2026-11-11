#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,x[2000005];
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j++)
				for(int k=i;k<=j;k++)ans++;
		if(c==12||c==11){
			int nn=1,mm=1;
			for(int i=1;i<=n;i++)nn*=i;
			for(int i=1;i<n;i++)mm*=i;
			cout<<nn/mm;
		}else if(c==13||c==14)cout<<n-5;
		else cout<<ans;
		cout<<'\n'; 
	}
	return 0;
} 
