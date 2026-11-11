#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],cnt,ans=0xffffff;
bool vis[N];
vector<int> num[35];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<30;j++)
			if(a[i]&(1<<j))
				num[j].push_back(i);
	for(int i=29;i>=0;i--){
		if(num[i].size()<m)continue;
		for(int j=num[i].size()-1;j>=0;j--){
			if(!vis[num[i][j]])
				ans&=a[num[i][j]],
				cnt++,
				vis[num[i][j]]=1;
			if(cnt==m)break;
		}
		if(cnt==m)break;
	}
	if(cnt<m)ans=0;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
