//¿ÓÈ»∫≠ GZ-J00046
#include<iostream>
using namespace std;
int n,m;
int a[500001];
int ans[300001];
int count[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=n,j=n;i>=1;--i,j=i){
		if(!count[a[i]])count[a[i]]=i;
		while(j<=n){
			j=count[a[j]];
			++ans[a[j]];
			++j;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	return 0;
}
