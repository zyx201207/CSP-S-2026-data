#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ans,mL; //mL-maxLength
int Pow[40];
string s[N];
int cnt[40];
vector<int> b[40],be[N]; //binary  binary_exist
bool dropped[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		int t;
		cin>>t;
		if (t==0) s[i]="0";
		while (t){
			s[i].push_back(t%2+'0');
			t/=2;
		}
		mL=max(mL,(int)(s[i].size()-1));
		for (int j=0;j<s[i].size();++j){
			if (s[i][j]=='1'){
				++cnt[j];
				be[i].push_back(j);
			}
			else b[j].push_back(i);
		}
	}
	Pow[0]=1;
	for (int i=1;i<=mL;++i) Pow[i]=Pow[i-1]*2;
	for (int i=1;i<=n;++i)
		if (s[i].size()<=mL)
			for (int j=s[i].size();j<=mL;++j)
				b[j].push_back(i);
	for (int i=mL;i>=0;i--){
		if (cnt[i]>=m){
			ans+=Pow[i];
			for (auto p:b[i])
				if (!dropped[p]){
					dropped[p]=1;
					for (auto q:be[p])
						--cnt[q];
				}
		}
	}
	cout<<ans;
	return 0;
}
