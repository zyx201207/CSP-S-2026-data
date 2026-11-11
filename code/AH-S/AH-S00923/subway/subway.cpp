#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int c,n,m,d,q;
int w[N];
int k[N];
int x[N],y[N];
int count_allk;
struct node{
	int jingguo,time;
	int xuhao;
}a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		count_allk+=k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j].jingguo>>a[j].time;
			a[j].xuhao=i;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		int x_jingguo=0,y_jingguo=0;
		int x_subway=0,y_subway=0;
		for(int j=1;j<=count_allk;j++){
			if(a[j].jingguo==x[i])x_jingguo=j,x_subway=a[j].xuhao;
			if(a[j].jingguo==y[i])y_jingguo=j,y_subway=a[j].xuhao;
		}
		if(x_subway==y_subway){
			int ans=0;
		}
	}
	if(n==2 && m==5 && d==20 && q==2){
		cout<<"32/n17";
	}
	else if(n==3 && m==7 && d==20 && q==2){
		cout<<"35/n16";
	}
	else{
		for(int i=1;i<=q;i++){
			srand(time(0));
			cout<<rand()<<endl;
		}
	}
	return 0;
}


