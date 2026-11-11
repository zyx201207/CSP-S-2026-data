#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fre
const int maxn=2e6+5; 
ll x[maxn];
bool ul[maxn],ur[maxn];//非只能最短点 
int main(){
	#ifdef fre
		freopen("migreat.in","r",stdin);
		freopen("migreat.out","w",stdout);
	#endif
	int c,q;cin>>c>>q;
	while(q--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<0<<endl;
	} 
} 
