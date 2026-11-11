#include<bits/stdc++.h>
using namespace std;
int n, m, a[500010], ans[300010], tt[300010];
bool t[500010];
vector<int> ve[300010];
void solve(int x){
	for(int i=x; i<=n; i++){
		t[i]=0;
	}
	for(int i=1; i<=m; i++){
		tt[i]=0;
	}
	for(int i=x; i<=n; i++){
		t[i]=1;
		for(int j=0; j<(int)(ve[a[i]].size()); j++){
			int v=ve[a[i]][j];
			if(v>=x && v<i){
				for(int k=v; k<i; k++){
					if(t[k]==1){
						t[k]=0;
					}
				}
			}
		}
	}
	for(int i=x; i<=n; i++){
		if(t[i]==1){
			tt[a[i]]=1;
		}
	}
	for(int i=1; i<=m; i++){
		ans[i]+=tt[i];
	}
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		ve[a[i]].push_back(i);
	}
	int f=1;
	for(int i=1; i<=n; i++){
		if(a[i-1]>a[i]){
			f=0;
			break;
		}
	}
	if(f==1){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				tt[j]=0;
			}
			for(int j=i; j<=n; j++){
				tt[a[j]]=1;
			}
			for(int j=1; j<=m; j++){
				ans[j]+=tt[j];
			}
		}
		for(int i=1; i<=m; i++){
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	for(int i=1; i<=n; i++){
		solve(i);
	}
	for(int i=1; i<=m; i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
