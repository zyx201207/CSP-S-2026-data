#include<bits/stdc++.h> 
using namespace std;
int n,m;
int s[500005];
bool f[300005];
int a[500005];
int ans[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		memset(s,0,sizeof s);
		memset(f,0,sizeof f);
		int cnt = 0;
		for(int j = i;j<=n;j++){
			if(!f[a[j]]){
				s[cnt]=a[j],cnt++,f[a[j]]=1;
			}else{
				while(s[cnt]!=a[j]){
						f[s[cnt]]=0;
						s[cnt]=0;
						cnt--;
				}
				cnt++;
			}
		}
		for(int j = 0;j<=cnt;j++){
			ans[s[j]]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
