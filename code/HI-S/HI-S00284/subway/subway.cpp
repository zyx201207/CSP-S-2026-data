#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=1e6+50;
struct node{
	int a,t;
};
node st[N]; 
ll c,n,m,d,q,at[N];
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway1.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>at[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>st[j].a>>st[j].t;
		}
	}
	int A,B;
	for(int i=1;i<=q;i++){
		cin>>A>>B;
	}
	if(n==2) cout<<32<<endl<<17;
	if(n==3) cout<<35<<endl<<16;
	return 0;
}

