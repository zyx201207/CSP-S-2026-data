#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n ,m;
int a[N];
bool vis[N];
int ans[N];
vector<int> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in" ,"r" ,stdin);
	freopen("card.out" ,"w" ,stdout);
	cin >> n >> m;
	for(int i=1;i <= n;i++){
		cin >> a[i];
	}
	for(int i=1;i <= n;i++){
		for(int j=i;j <= n;j++){
			bool bo=0;
			for(int k=i;k < j;k++){
				if(a[k]==a[j]){
					bo=1;
				}
				if(bo=1) vis[k]=0;
			}
			vis[j]=1;
		}
		for(int j=i;j <= n;j++){
			if(vis[j]==1) ans[a[j]]++;
		}
		memset(vis ,0 ,sizeof(vis));
	}
	for(int i=1;i <= m;i++) cout << ans[i] << '\n';
	return 0;
} 


