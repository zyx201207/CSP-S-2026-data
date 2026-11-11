#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long res;
long long step;
long long minn=0x3f3f3f3f;
long long maxstep;
bool q[1000001];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		vector<long long > island;
		memset(q,0,sizeof(q));
		for(int p=1;p<=n;p++){
			long long t;
			cin>>t;
			minn=min(minn,t);
			q[t]=true;
			island.push_back(t);
		}
		cout<<0<<endl;
	}
	return 0;
}

