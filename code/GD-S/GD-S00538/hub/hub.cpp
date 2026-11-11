#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll =long long;
using pii = pair<int, int>;
const int N=500+9,inf=1e9+9;
vector<int> ve[N];
void solved(){//Îå·ÖÖÓ  
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		ve[x].push_back(y),ve[y].push_back(x);
	}
	for(int mask=0;mask<=(1<<n)-1;mask++){
		int cnt=0;
		for(int j=0;j<n;j++)if(mask>>j & 1)cnt++;
		if(cnt>=k)continue;
		for(int i=1;i<=n;i++){
		
		}
	}
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int num;cin>>num;
	int t;cin>>t;
	while(t--)
	solved();
	return 0;
} 
/*
keep thinking  determined  calmed down!

*/





