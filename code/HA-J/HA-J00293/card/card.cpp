#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define p pair<int,int>
#define int long long
using namespace std;
int n,m,ans[500005];
int b[500005],cnt[500005];
vector<p>e;
signed main(){
	fre("card");
	cin>>n>>m;
	int a[n];
	for(int&i:a)cin>>i;
	for(int*i=a;i<a+n;i++){
		if(b[*i]){
//			c[b[*i]]=i-a+1;
			e.push_back({b[*i],i-a+1});
		}
		b[*i]=i-a+1;
	}
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++){
		int r=i;
		cnt[r]++;
		while(r<n){
			int x=lower_bound(e.begin(),e.end(),make_pair(r,r))-e.begin();
//			cout<<x<<' ';
			if(x>=e.size())break;
			if(e[x].first>=r){
				cnt[e[x].first]--;
				r=e[x].second;
				cnt[r]++;
//				cout<<r<<endl;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=cnt[i];
		ans[a[i-1]]+=sum;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
