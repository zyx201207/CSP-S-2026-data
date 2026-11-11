#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int c,q,a[N],ans=0,mi=9999999;
void dg(int now,int end,int m,int n,int ti){
	if(now==end){
		if(ti<mi){
			mi=ti;
			ans=1;
		}else if(ti==mi){
			ans++;
		}
		return;
	}
	for(int i=now+1;i<=end;i++){
		if(a[i]-a[now]>m)break;
		dg(i,end,m,n,ti+1); 
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
		int n,m,y=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int st=1;st<=n;st++){
			for(int en=st+3;en<=n;en++){
				ans=0;
				mi=9999999;
				dg(st,en,m,n,0);
				if(ans==2){
					//cout<<st<<" "<<en<<endl;
					y++;
				}
			}
		}
		cout<<y<<endl;
	}
	return 0;
} 
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 1
//5 2
//1 2 3 4 5

//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
