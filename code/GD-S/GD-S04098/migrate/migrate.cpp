#include<bits/stdc++.h>
using namespace std;


//喜极而泣 
//hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
// ----------------------------------------- //
//      *     ##########        *                 //
// -----|-----------------------|----------- //
//        |                            \   |                //
//      |||||||||||||\    |||||||||||||||||||\\                  //
//hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d,cnt=0;
		cin>>n>>d;
		long long x[n+5]={},f[n+5]={};
		for(int j=1;j<=n;j++){
			cin>>x[j];
			f[j-1]=x[j]-x[j-1];
		}
		for(int j=1;j<=n;j++){
			if(f[j]>=(d+1)/2&&f[j]<=d){
				cnt++;
			}
		}
		cout<<cnt/d<<'\n';
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