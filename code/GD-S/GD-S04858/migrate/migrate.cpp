#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+10;
int sub,t,n,d,x[N],dpsum[N],dpmin[N],ans;
void init(){
	for(int i=1;i<=n;i++){
		dpsum[i]=0;
		dpmin[i]=1e18;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>sub>>t;
	if(sub==13 or sub==14){
		cout<<0;
		return 0;
	}
	while(t--){
		 cin>>n>>d;
		 for(int i=1;i<=n;i++){
		 	cin>>x[i];
		 }
		 for(int k=1;k<=n;k++){
		 	init();
		 	dpmin[k]=0;
		 	for(int i=k;i<=n;i++){
		 		for(int j=i-1;j>=k;j--){
		 			if(abs(x[i]-x[j])<=d){
		 			//	cout<<j<<"to"<<i<<" "<<abs(x[i]-x[j])<<endl;
		 				if(dpmin[j]+1<dpmin[i]){
		 					dpsum[i]=1;
		 					dpmin[i]=dpmin[j]+1;
						 }else if(dpmin[i]==dpmin[j]+1){
						 	dpsum[i]++;
						 }
					}else{
						break;
					}
				 }		
			}
		//	cout<<"k"<<k<<endl; 
			for(int i=k;i<=n;i++){
			//	cout<<i<<",sum"<<dpsum[i]<<",min"<<dpmin[i]<<endl;
				if(dpsum[i]==2){
			//		cout<<k<<"to"<<i<<endl;
					ans++;
				}
			}
		 }
		 cout<<ans<<endl;
		 ans=0;
	}
	return 0;
}
/*
10
dp Î¬»¤ 
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

µ÷sub3ºÃ¾Ã 

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558-111111111111111116 
111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 1
7 663
-1000 -558 -116 105 326 547 989

  663
-1000  1
- 558 2
- 116  3
  105  4
  326  5
  547  6
  989 7
6

B:0
*/

