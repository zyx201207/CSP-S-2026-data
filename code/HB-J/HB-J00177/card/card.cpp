#include <bits/stdc++.h>
using namespace std;

int pos[300100];
int n,m,a[500100];
int sta[300100],top = -1;
int mrklst[300100];
int ans[300100];
bool f = 1;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i >= 1 && a[i] >= a[i - 1])mrklst[a[i - 1]] = i - 1;
		if(i != 1 && a[i] < a[i - 1])f = 0;
	}
	if(f == 1){
		for(int i = 1;i <= m;i++){
			cout << mrklst[i] << " ";
		}
		return 0;
	}
	
	for(int i = 1;i <= n;i++){
		memset(pos,-1,sizeof(pos));
		memset(sta,0,sizeof(sta));
		top = -1;
		for(int j = i;j <= n;j++){
			int t = a[j];
			if(pos[t] == -1){
				pos[t] = ++top;
				sta[top] = t;
			}else{
				for(int k = pos[t] + 1;k <= top;k++){
					pos[sta[k]] = -1;
				}
				top = pos[t];
			}
		}
		//cout << "Round " << i << ":";
		for(int j = 0;j <= top;j++){
			ans[sta[j]]++;
			//cout << sta[j] << " ";
		}
		//cout << '\n';
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}

	return 0;
}
