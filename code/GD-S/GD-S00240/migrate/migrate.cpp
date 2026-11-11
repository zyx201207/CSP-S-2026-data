#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,sz[2000006];
void solve(){
	cin>>n>>d;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>sz[i];
	}
	long long cnt=0;
	for(int i=1;i<=n-3;i++){
		if(sz[i+1]-sz[i]<=d && sz[i+3]-sz[i+1]<=d && sz[i+3]-sz[i]>d){
			if(sz[i+2]-sz[i]<=d && sz[i+3]-sz[i+2]<=d && sz[i+3]-sz[i]>d){cnt++;}
		}
		int op=0;
		if(sz[i+1]-sz[i]<=d && sz[i+4]-sz[i+1]<=d && sz[i+4]-sz[i]>d){op++;}
		if(sz[i+2]-sz[i]<=d && sz[i+4]-sz[i+2]<=d && sz[i+4]-sz[i]>d){op++;}
		if(sz[i+3]-sz[i]<=d && sz[i+4]-sz[i+3]<=d && sz[i+4]-sz[i]>d){op++;}
		if(op==2){cnt++;}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
} 
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
