//GZ-J00293 »Æçûä¿
#include<bits/stdc++.h>
using namespace std;
int a[500010],f[500010],ans[500010];
stack<int>sta;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 1;i <= n;i++){
		while(!sta.empty())sta.pop();
		memset(f,0,sizeof(f));
		for(int j = i;j <= n;j++){
			if(!f[a[j]]){
				f[a[j]]++;
				sta.push(a[j]);
			}
			else{
				while(sta.top() != a[j]){
					f[sta.top()]--; 
					sta.pop();
				}
				f[sta.top()]--;
				sta.pop();
				f[a[j]]++;
				sta.push(a[j]);
			}
		}
		for(int i = 1;i <= m;i++){
			if(f[i])ans[i]++;
		}
	}
	for(int i = 1;i <= m;i++)cout << ans[i] << " ";
	return 0;
}
