#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<long long> a[31];
void wat(long long k)
{
	if(k>=1&&k<2) a[0].push_back(k);
	else if(k>=2&&k<4) a[1].push_back(k);
	else if(k>=4&&k<8) a[2].push_back(k);
	else if(k>=8&&k<16) a[3].push_back(k);
	else if(k>=16&&k<32) a[4].push_back(k);
	else if(k>=32&&k<64) a[5].push_back(k);
	else if(k>=64&&k<128) a[6].push_back(k);
	else if(k>=128&&k<256) a[7].push_back(k);
	else if(k>=256&&k<512) a[8].push_back(k);
	else if(k>=512&&k<1024) a[9].push_back(k);
	else if(k>=1024&&k<2048) a[10].push_back(k);
	else if(k>=2048&&k<4096) a[11].push_back(k);
	else if(k>=4096&&k<8192) a[12].push_back(k);
	else if(k>=8192&&k<16384) a[13].push_back(k);
	else if(k>=16384&&k<32768) a[14].push_back(k);
	else if(k>=32768&&k<65536) a[15].push_back(k);
	else if(k>=65536&&k<131072) a[16].push_back(k);
	else if(k>=131072&&k<262144) a[17].push_back(k);
	else if(k>=262144&&k<524288) a[18].push_back(k);
	else if(k>=524288&&k<1048576) a[19].push_back(k);
	else if(k>=1048576&&k<2097152) a[20].push_back(k);
	else if(k>=2097152&&k<4194304) a[21].push_back(k);
	else if(k>=4194304&&k<8388608) a[22].push_back(k);
	else if(k>=8388608&&k<16777216) a[23].push_back(k);
	else if(k>=16777216&&k<33554432) a[24].push_back(k);
	else if(k>=33554432&&k<67108864) a[25].push_back(k);
	else if(k>=67108864&&k<134217728) a[26].push_back(k);
	else if(k>=134217728&&k<268435456) a[27].push_back(k);
	else if(k>=268435456&&k<536870912) a[28].push_back(k);
	else if(k>=536870912&&k<1073741824) a[29].push_back(k);
	else if(k>=1073741824&&k<2147483648) a[30].push_back(k);

}
bool twa(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		long long k;
		cin >> k;
		wat(k);
	}
	bool qw=true;
	long long ans=0;
	for(int i=30;i>=0;i--)
	{
		if(a[i].size()>=m)
		{
			qw=false;
			sort(a[i].begin(),a[i].end(),twa);
			for(auto as:a[i])
			{
				m--;
				//cout << as << ' ';
				if(ans==0) ans=as;
				else ans=(ans&as);
				if(m==0)
					break;
			}
			break;
		}
	}
	if(qw)
	{
		for(int i=30;i>=0;i--)
		{
			sort(a[i].begin(),a[i].end(),twa);
			for(auto as:a[i])
			{
				m--;
				//cout << as << ' ';
				if(ans==0) ans=as;
				else ans=(ans&as);
				if(m==0)
					break;
			}
			if(m==0)
				break;
		}
	}
	cout << ans;
	return 0;
}
