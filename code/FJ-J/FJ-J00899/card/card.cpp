#include<bits/stdc++.h>
using namespace std;
int a[500001],ans[300001],p[300010];
struct lx{
	bool c;
	int w;
}cs[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ps;
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=m;i++){
		ps=0;
		for(int j=1;j<=n;j++){p[j]=0;cs[j].c=0;cs[j].w=0;}
		for(int j=i;j<=n;j++){
			ps++;
			p[ps]=a[j];
			if(cs[a[j]].c==1){
				for(int k=cs[a[j]].w;k<=j;k++){p[k]=0;ps--;}
			}
			cs[a[j]].c=1;
			cs[a[j]].w=j;
		}
		for(int j=1;j<=ps;j++){
			if(p[j]!=0)ans[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}
