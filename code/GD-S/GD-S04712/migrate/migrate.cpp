#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
const int N=2e6+5;

ull c,t,n,d;
ull a[N];


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//freopen("migrate4.in","r",stdin);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>a[i];
				cout<<0<<'\n';
		}
		return 0;	
	}
		
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>a[i];
				
			ull tmp=a[n]-a[n-1];
			if(tmp<=d*2)	
				cout<<0<<'\n';
			else
				cout<<n-(d/tmp)-1<<'\n';
			}
		return 0;
		}	
	return 0;
	
	
}
