#include <bits/stdc++.h>
using namespace std;
int a[500010],t[500010],cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=i;j<=n;j++){
			int id=num+1;
			for(int k=1;k<=num;k++){
				if(t[k]==a[j]){
					id=k;
					break;
				}
			} 
			if(id!=num+1){
				for(int k=id+1;k<=num;k++) t[k]=0;
				num=id;
			}else{
				t[++num]=a[j];
			}
		}
		for(int j=1;j<=m;j++){
			for(int k=1;k<=num;k++){
				if(t[k]==j){
					cnt[j]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++) cout << cnt[i] << " ";
	return 0;
}
