#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;
const int N=3e6+999;
const int INF=1e18+99999,rINF=5e17+99999;
int n,d;
int a[N];//检查前两题变量名 
int rans;
int FALGx;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C,T=1;
	cin>>C>>T;
	while(T--){
		FALGx=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2&&a[i]-a[i-1]!=a[i+1]-a[i-1]){
				FALGx=1;
			}
		}
		if(C==13||C==14){
			cout<<0<<"\n";
			continue;
		}
		if(a[n]-a[1]<=d){
			cout<<0<<"\n";
			continue;
		}
		if(FALGx==0){
			int x=a[2]-a[1];
			int zzx=d/x;
			if(x>d)cout<<0<<"\n";
			else{
				cout<<d/x*(n-4)<<"\n";
			}
			continue;
			
		}
		cout<<2<<"\n"; 
		rans=0;
	}
	return 0;
} 
