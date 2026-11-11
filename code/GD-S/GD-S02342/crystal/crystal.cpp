#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,LL> PII;
const int N=5e5+10,INF=0x3f3f3f3f;
int n;
int ans;
LL m;
LL a[N];
struct BOX{
	LL a;
	int cnt;
	bool st;
};
bool cmd(BOX a,BOX b){
	return a.cnt>b.cnt;
}
int find_ans(){
	vector<PII> temp;
	for(int i=1;i<=n;i++){
		int cnt=0;
		LL xx=a[i];
		while(a[i]==xx) i++,cnt++;
		temp.push_back({cnt,xx});
	}
	sort(temp.begin(),temp.end());
	return temp.back().x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ans=find_ans();
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]) continue;
		int x=a[i];
		int res=0;
		for(int j=n;j>=1;j--){
			if(a[j]>=x) continue;
			res+=(x-a[j]);
		}
		if(res>m) break;
		ans=max(ans,find_ans());
		//cout<<x<<"::"<<res<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
