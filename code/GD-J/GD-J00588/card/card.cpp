#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
const int M = 300010;
int n,m,a[N],f[N],ans[M],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 1;i <= n;i++){
		memset(f,0,sizeof f);
		cnt = 0; 
		for(int j = 1 + i - 1;j <= n;j++){
			f[++cnt] = a[j];
			bool t = false;
			for(int k = 1;k < j;k++){
				if(t && f[cnt] == f[k]) t = true;
				if(t) f[k] = 0;
			}
			if(t) f[cnt] = a[j];
		}
		for(int j = 1;j <= cnt;j++) ans[f[j]]++;
	}
	for(int i = 1;i <= m;i++){
		if(ans[i] != 0){
			cout<<ans[i];
			if(i != m) cout<<" ";
		}		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
