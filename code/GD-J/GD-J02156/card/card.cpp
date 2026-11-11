#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
stack<int> a;
int n,m,num[N],cnt[M],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>num[i];
	for(int u=1;u<=n;u++){
		memset(cnt,0,sizeof(cnt));
		while(!a.empty()) a.pop();
		for(int i=u;i<=n;i++){
			if(cnt[num[i]]==1) while(a.top()!=num[i]) cnt[a.top()]=0,a.pop();
			a.push(num[i]);
			cnt[num[i]]=1;
		}
		for(int i=1;i<=m;i++) if(cnt[i]==1) ans[i]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
