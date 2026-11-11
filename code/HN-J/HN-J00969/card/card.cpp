#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,t[300005],z[300005],x[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		int q=1;
		for (int j=i;j<=n;j++){
			if(z[a[j]]==0){
				z[a[j]]=1;
				x[q]=a[j];
				q++;
			}
		}
		for (int j=1;j<=m;j++){
			if(z[j]==1){
				t[j]++;
			}
		}
	}
	for (int i = 1;i <= m;i++){
		cout << t[i] << " ";
	}
	return 0;
}

