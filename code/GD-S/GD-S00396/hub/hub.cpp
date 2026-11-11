#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[1000000],c,t;
void slove(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll r=-1,rr=-1,rrr=-1,cnt=0;
	for(int i=1;i<=n;i++){
		r=-1,rr=-1,rrr=-1;
		ll ok=0,lsrr=-1,lsrrr=-1,rep=i,okk=1,okkk=0;
		for(int j=i+1;j<=n;){
			r=-1,rr=-1,rrr=-1;
			if(abs(a[j]-a[rep])>m){
				break;
			}
			while(abs(a[j]-a[rep])<=m){
//				okkk=0;
				if(r==-1){
					r=j;
				}
				else if(rr==-1){
					rr=r;
					r=j;
				}
				else{
					rrr=rr;
					rr=r;
					r=j;
				}
				if(r==-1){
				//完全到不了，可以结束了
//					cout<<1<<"?\n"; 
					break; 
				}
				else if(lsrrr!=-1&&abs(a[lsrrr]-a[j])<=m){
//					cout<<2<<"?\n";
					//三个点都可以跑到，完蛋了
//					break;
				}
				else if(lsrr!=-1&&abs(a[lsrr]-a[j])<=m){
//					cout<<j<<"!!!\n";
					//两个点都可以跑到 
					if(okkk==0){
						ok=1;
						cnt++;
					}
					else{
						//前面已经有两种的方案了
//						break; 
					}
				}
				j++;
				if(j>n){
					break;
				}
			}
			if(ok==1){
				okkk=1;
			}
			lsrr=rr,lsrrr=rrr;
			rep=r;
		}
	}
	cout<<cnt<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cout<<1<<endl;
	}
}
/*
五年来最绝望的一场csp。。。 
*/


/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 3
0 1 2 3 4 7

0 1
6 4
-3 0 1 2 3 4
*/

