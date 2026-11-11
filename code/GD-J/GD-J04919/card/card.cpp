#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005],ans[50005];
struct node{
	bool dat;
	int num;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	for(int i = 1;i<=n;i++){
		node v[50005] = {};
		for(int j = i;j<=n;j++){
			if(v[a[j]].dat){
				for(int k = v[a[j]].num;k<j;k++){
					v[a[k]].dat = 0,v[a[k]].num = 0;
				}
				v[a[j]].dat = 1;
				v[a[j]].num = j;
			}else v[a[j]].dat = 1,v[a[j]].num = j;
		}
		for(int j = 1;j<=m;j++) if(v[j].dat) ans[j]++;
	}for(int i = 1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
