#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[500010];
	int flag[500010],ans[500010];
	long long [500010]s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof(flag));
		int h=1,t=1;
		for(int j=i;j<=n;j++){
			if(flag[a[j]]==0){
				h++;
				s[h]=a[j];
				flag[a[j]]=1;
			}
			else{
				while(s.top()!=a[j]){
					flag[s[t]]=0;
					s.pop();
				}
				s.pop();
				s.push(a[j]);
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
