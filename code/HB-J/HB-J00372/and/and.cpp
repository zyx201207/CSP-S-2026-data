#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200009];

int xj[1009],book[1009],an = INT_MIN;
void dfs(int dj,int jg){
    if(dj > jg){
        int t = xj[1];
        for(int i = 2;i <= jg;i++){
            t = t & xj[i];
        }
        an = max(t,an);
        return ;
    }
    for(int i = 0;i < n;i++){
		if(book[i] != 1){
            xj[dj] = a[i];
            book[i] = 1;
            dfs(dj + 1,jg);
            book[i] = 0;
        }
    }
    return  ;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0;i < n;i++) cin >> a[i];

	int ans = INT_MIN;
	if(m == 1){
		for(int i = 0;i < n;i++) ans = max(ans,a[i]);
		cout << ans;
	}
	else if(m == 2){
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				ans = max(ans,(a[i] & a[j]));
			}
		}
		cout << ans;
	}
    else {
        dfs(1,m);
        cout << an;
    }

	return 0;
}
