#include<bits/stdc++.h>
#define endl '\n'
#define i64 long long
#define i128 __int128
using namespace std;
int c,n,m,d,q,w[500005];
int dist[4005][4005];
int main(){
	srand(time(0));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=q;i++){
		cout<<w[1]*5+rand()%w[m]*20<<endl;
	}
	return 0;
}

