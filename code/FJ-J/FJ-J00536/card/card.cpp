#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int a[MAXN],cnt[MAXN],ans[MAXN],ps,d;
int m,n;
int main(){
	freopen("card.in","r","stdin");
	freopen("card.out","w","stdout");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=ps;k++){
				if(a[j]==cnt[k]){
					d++;
					for(int l=k+1;l<=ps;l++){
						cnt[l]=0;
					}
					ps=k;
					break;
				}
			}
			if(d==0){
				ps++;
				cnt[ps]=a[j];
			}
			d=0;
		}
		for(int o=1;o<=ps;o++){
			ans[cnt[o]]++;
			cnt[o]=0;
		}
		ps=0;
	}
	for(int i=1;i<=m;i++){
		if(i!=m){
			cout << ans[i] << " ";
		}else{
			cout << ans[i];
		}
	}
	return 0;
}
