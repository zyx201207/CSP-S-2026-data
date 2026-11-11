#include<bits/stdc++.h>
using namespace std;
int c,T;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		int n,d;
		cin>>n>>d;
		int a[2000010];
		int dis=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dis=a[i]-a[i-1];
		}
		int cnt=0;
		while(d>=dis){
			d-=dis;
			cnt++;
		}
		int ans=0;
		for(int i=1;i+2*cnt-1<=n;i++){
			ans+=cnt-1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//17:37 
//怎么骗分写炸了
//我是真的肺雾啊 
//为什么不输入就直接返回了
//??????????
//文件夹风水不好？ 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
//为什么Linux能运行啊
//这是何意味啊
//18:01
//在Linux下改出来了
//我真
//+8pts,全是骗分
//怎么题还出错了
