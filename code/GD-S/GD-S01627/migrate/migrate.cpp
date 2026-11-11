#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2000005;
int c,T,n,d,x[MAXN],s[MAXN];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<n;i++)
			s[i]=x[i+1]-x[i];
		for(int i=1;i<=n;i++){
			if(d>s[i]){
				while(d>s[i])
					i++;
				cnt++; 
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
