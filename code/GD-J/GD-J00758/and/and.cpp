#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
constexpr int N=2e5+5;
int n,m,a[N];
bool tag[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tag[i]=true;
	}
	int ans=0;
	for(int w=30;w>=0;w--){
		int cnt=0;
		vector<int>vec;
		for(int i=1;i<=n;i++){
			if(!tag[i])continue;
			if((a[i]>>w)&1){
				cnt++;
			}else{
				vec.push_back(i);
			}
		}
		if(cnt>=m){
			ans|=1<<w;
			for(int &i:vec){
				tag[i]=false;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
