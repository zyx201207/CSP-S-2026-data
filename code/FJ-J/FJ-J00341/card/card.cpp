#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=5e5+5;
constexpr int MAXM=3e5+5;
int n,m;
int a[MAXN];
int tong[MAXM];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int> vec;
		for(int j=i;j<=n;j++){
			vector<int>::iterator pos=find(vec.begin(),vec.end(),a[j]);
			if(pos!=vec.end()){
				vec.erase(pos,vec.end());
				vec.push_back(a[j]);
			} else vec.push_back(a[j]);
		}
		for(int j:vec)
			tong[j]++;
	}
	for(int i=1;i<=m;i++) cout<<tong[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
