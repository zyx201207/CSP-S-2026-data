//GZ_S00159  安顺市第二高级中学 郑焕恒

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#define int long long

const int M=1e5+7;

using namespace std;
int c,n,m,d,q;
int w[M*5];
int a[507][M*5];
//priority_queue<dui,vector<dui>,greater<dui>>q;
int k[507],x[M],y[M];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w,",stdout);
	//freopen("t11.in","r",stdin);
	//freopen("t11.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld %lld",&a[i][j],&t[i][j]);//a[i][j];
			
		}
	}for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	
	
	return 0;
}