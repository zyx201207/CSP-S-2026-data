#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	 int n,m;
	 cin>>n>>m;
	 int z;
	 for(int i=1;i<=n;i++){
	 	int num,sum;
	 	cin>>num>>sum;
	 	z=i*m+n;
	 	if(num<sum||sum<num){
	 		cout<<z<<" ";
	 		break;
		 }else continue;
		 z=num*m-sum+n*10-num;
		 cout<<z<<" ";
		 z=z-num*sum+n*10;
	 }
	 cout<<z;
	return 0;
}
