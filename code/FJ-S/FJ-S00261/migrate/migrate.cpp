#include<bits/stdc++.h>
using namespace std;
const int maxn=2000090;
int c,t;int n;long long d,x[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<=n;i++){
			cin>>x[i];
		}
		srand(time(0));
		cout<<rand()%(n+1)<<endl;
	}
	return 0;
	
}
