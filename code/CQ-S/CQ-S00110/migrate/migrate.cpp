//啧啧啧完蛋了
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+6;
int c,T,n,d,a[N];

void workA(){//等差 
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int del=a[2]-a[1];
		if(del<0)del=-del;
	//	cout<<del<<' '<<d<<endl;
		if(del>=d){
			cout<<0<<'\n';
			continue;
		}
		int mx=d/del;
		int la=mx+mx-1;
		if(la>n)cout<<0<<'\n';
		else cout<<n-la<<'\n';
		
	}
}
void workB(){
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<0<<'\n';
	}
}

//int dfs1(int st){
//	if()
//}
//
//void work666(){
//	while(T--){
//		cin>>n>>d;
//		for(int i=1;i<=n;i++){
//			cin>>a[i];
//		}
//		int ans=0;
//		for(int st=1;st<=n;st++){
//			for(int ed=1;ed<=n;ed++){
//				if(st<ed){//向右 
//					if(dfs1(st)==2){
//						ans++;
//					}
//				}
//			}
//		}
//	}
//}


signed main(){
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
//	if(1<=c&&c<=6){
//		work666();
//	}
	if(11<=c&&c<=12){
		workA();
	}
	else if(13<=c&&c<=14){
		workB();
	}
	return 0;
}
