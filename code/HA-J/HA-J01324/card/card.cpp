#include<bits/stdc++.h>
using namespace std; 
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
if(m==2){
	long long ans1=0,ans2=0;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		if(a==1){
			ans1=i;
		}else{
			ans2=i;
		}
	}cout<<ans1<<" "<<ans2;
}
return 0;
}
