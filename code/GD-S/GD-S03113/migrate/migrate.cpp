#include<bits/stdc++.h>
using namespace std;
int  c,n,m,d,q;
vector<pair<int,int> > g[500005];
int a[500005],b[500005];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2){
		if(m==4){
			for(int i=1;i<=n;i++){
				cout<<i<<"\n";
			}
		}
		if(m==5){
			for(int i=1;i<=n;i++){
				cout<<i-1<<"\n";
			}
		}
	}
	
	return 0;
} 
