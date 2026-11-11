#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],pos[210],ls[300010];
vector<int> b;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=500&&m<=200){
		for(int i=1;i<=m;i++){
			int cnt=0;
			for(int j=1;j<=n;j++){
				memset(pos,0,sizeof pos);
				b.clear();
				for(int k=j;k<=n;k++){
					if(pos[a[k]]==0) pos[a[k]]=k,b.push_back(a[k]);
					else{
						for(int l=b.size()-1;b[l]!=a[k];l--){
							pos[b[l]]=0;
							b.pop_back();
						}
						b.push_back(a[k]);
						pos[a[k]]=k;
					}
				}
				for(auto k:b){
					if(k==i){
						cnt++;
						break;
					}
				}
			}
			cout << cnt << " ";
		}
	}else{
		for(int i=n;i>=1;i--){
			if(ls[a[i]]==0) ls[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout << ls[i] << " ";
		}
	}
    return 0;
}
