//贵阳市第三中学 游子乐GZ-J00363 
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n,m,ma = 0;
int a[N],b[N];
bool use[N];

void dfs(int k,int start){
	if(k == m+1){
		int sumn = INT_MAX; 
		for(int i = 1;i <= m;i++){
			sumn = min(a[b[i]],sumn);
		}
		for(int i = 1;i <= m;i++){
			sumn = (sumn & a[b[i]]);
		}
		ma = max(sumn,ma);
	}
	else{
		for(int i = start;i <= n;i++){
			if(!use[i]){
				use[i] = 1;
				b[k] = i;
				dfs(k+1,start+1);
				use[i] = 0;
			}
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(1,1);
	cout << ma;
	return 0;
}
