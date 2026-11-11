#include<iostream>
using namespace std;

const int N=2e6+10;
const int MAXN=1e5+5;

int a[N];
int ans[MAXN];
int n,d;
int sum=0,ansn=0;

void plan(int u,int v){
	if(a[u]+d<a[u+1]){
		sum--;
		return;
	}
	sum++;
	if(v-u<=2){
		if(sum==2)ansn++;
		return;
	}
	int x=u;
	while(a[u]+d>=a[x]&&x<n-1){
		x++;
		plan(x,v);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int it=0;it<t;it++){
		cin >> n >> d;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		for(int i=0;i<n-3;i++){
			for(int j=i+3;j<n;j++){
				plan(i,j);
				sum=0;
			}
		}
		ans[it]=ansn;
		ansn=0;
	}
	for(int i=0;i<t;i++){
		cout << ans[i] << '\n';
	} 
}
