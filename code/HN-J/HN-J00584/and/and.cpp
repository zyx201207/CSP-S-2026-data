#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
long long a[N];
bool pd[N];
bool px(long long x,long long y){
	return x>y;
}
struct lylf{
	long long zz;
	int wz;
}zpp[N];
bool px1(lylf x,lylf y){
	return x.zz>y.zz;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
   for(int i=1;i<=n;i++){
   	cin>>a[i];
   }
   sort(a+1,a+n+1,px);
   int kg=a[1];
   pd[1]=1;
   int sz;
   for(int i=1;i<m;i++){
 sz=0;
   	for(int j=1;j<=n;j++){
   		if(pd[j]==0) {
   			sz++;
   			zpp[sz].wz=j;
			   zpp[sz].zz=kg&a[j]; 
		   }
	   }
	   sort(zpp+1,zpp+sz+1,px1);
	   pd[zpp[1].wz]=1;
	   kg=zpp[1].zz;
	 
   }
   cout<<kg;
} 
