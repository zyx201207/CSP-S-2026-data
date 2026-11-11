#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353,inf=0x3f3f3f3f3f3f3f3f;
const int N=5e5+10,M=2e5+10;
mt19937 rnd(random_device{}());
namespace Anaxa{
    int n,m;
    map<int,int>mp;
    vector<pair<int,int>>vec;
	void main()
	{
		cin >> n >> m;
        while(n--)
        {
            int x;cin >> x;
            mp[x]++;
        }
        for ( auto [x,y]:mp )vec.push_back({x,y});
        int p=0,ans=vec[0].second,cnt=vec[0].second,used=0;
        for ( int i = 1 ; i < vec.size() ; i++ )
        {
            used+=cnt*(vec[i].first-vec[i-1].first);cnt+=vec[i].second;
            while(used>m)
            {
                used-=vec[p].second*(vec[i].first-vec[p].first);
                cnt-=vec[p++].second;
            }
            ans=max(ans,cnt+(p!=0?(m-used)/(vec[i].first-vec[p-1].first):0ll));
        }
        cout << ans << endl;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	Anaxa::main();
	return 0;
}
/*
g++ crystal.cpp -O2 -std=c++14 -Wall
./a.out < crystal1.in > crystal.out
diff crystal.out crystal1.ans -Z -B
./a.out < crystal2.in > crystal.out
diff crystal.out crystal2.ans -Z -B
./a.out < crystal3.in > crystal.out
diff crystal.out crystal3.ans -Z -B
./a.out < crystal4.in > crystal.out
diff crystal.out crystal4.ans -Z -B
*/