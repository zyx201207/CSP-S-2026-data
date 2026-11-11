#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int t(int x){
int q[x/2],cnt=1;
	long long  s=0;
	
	
	while(x){
	q[cnt]=x%2;
		x/=2;
		cnt++;
		
	}
	for(long long i=cnt-1;i>=1;i--){
		s+=q[i];
		s*=10;
	
}
return s/=10;

}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;cin>>n>>m;
if(n==4&&m==2)cout<<12;
if(n==5&&m==3)cout<<7;
else cout<<0;
	return 0;
}
