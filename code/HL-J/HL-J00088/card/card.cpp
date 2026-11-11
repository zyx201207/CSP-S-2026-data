#include <bits/stdc++.h>
using namespace std;

int n,m,a[int(5e5+5)];
stack<int>s;
bool cnt[int(3e5+5)];
int ans[int(3e5+5)];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		while(!s.empty()) s.pop();
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]==1)
				while(s.top()!=a[j]){
					cnt[s.top()]=0;
					s.pop();
				}
			else{
				s.push(a[j]);
				cnt[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(cnt[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
