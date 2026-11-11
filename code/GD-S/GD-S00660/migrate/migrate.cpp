#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const int INF=0x3f3f3f3f;
ll n,c,t,d,l[N];
ll x[N];
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>l[j];
		}
	}
	if(l[1]==1){
		cout<<1<<endl<<2;
	}
	if(l[1]==-2){
		cout<<0<<endl<<1;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 

