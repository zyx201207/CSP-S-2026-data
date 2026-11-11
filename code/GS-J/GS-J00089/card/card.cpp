#include<bits/stdc++.h>
using namespace std;
int n,m;
bool b[3001];
int a[500005];
int now[500005],ans[300004],lennow = 0;
int main(){
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		lennow = 0;
		memset(b,false,sizeof(b));
		for(int j = i;j <= n;j++){
			if(b[a[j]] == false){
				now[++lennow] = a[j];
				b[a[j]] = true;
			}else{
				int cnt = lennow;
				for(int k = 1;k <= lennow;k++){
					if(now[k] == a[j]){
						lennow = k;
						break;
					}
				}
				for(int k = cnt;k >= lennow + 1;k--){
					b[now[k]] = false;
				}
			}
		}	
		cout << i << " " << lennow << endl;
		for(int j = 1;j <= lennow;j++){
			cout << now[j] << " ";
			ans[now[j]]++;
		}
		cout << "\n";
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
}
