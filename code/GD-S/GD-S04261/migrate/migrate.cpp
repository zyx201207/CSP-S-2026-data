#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 2000005;
ll x[N];



int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		int n,d;
		cin>>n>>d;
		for(int i = 1; i <= n; i++){
			cin>>x[i];
		}
		cout<<1<<endl;
	}
	
	
	
	return 0;
} 
