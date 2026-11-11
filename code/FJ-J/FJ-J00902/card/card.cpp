#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5,M=3e5;
int n,m,a[N];
int dis[M],ans[M];

//void f(){
//	for(int i=1;i<=m;i++) cout<<dis[i]<<" ";
//	cout<<endl;
//}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) dis[j]=0;
//		cout<<i<<endl;
		for(int j=i;j<=n;j++){
			if(!dis[a[j]]) dis[a[j]]=j;
			else{
				for(int z=1;z<=m;z++){
					if(dis[z]>dis[a[j]] && dis[z]<j) dis[z]=0;
				}
				dis[a[j]]=j;
			}
//			f();
//			cout<<endl;
		}
		for(int j=1;j<=m;j++){
			if(dis[j]!=0) ans[j]++;
		}
//		cout<<">> ";
//		for(int j=1;j<=m;j++) cout<<ans[j]<<" ";
//		cout<<endl; 
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
