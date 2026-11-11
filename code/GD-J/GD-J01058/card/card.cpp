#include<iostream>
#include<vector>
using namespace std;
const int N=3e5+5;
int n,m;
int a[500005],b[N],f[N];
vector<int>v[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		int l=v[i].size();
		if(v[i][l-1]+1<=n){
			b[i]=a[v[i][l-1]+1];
		}
	}
	for(int i=1;i<=m;i++){
		int t=i,l=v[i].size();
		while(t!=0){
			f[t]+=l;
			t=b[t];
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",f[i]);
	}
	return 0;
}

