//GZ-J00533 邓梓清 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=-1;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
	scanf("%lld",&a[i]);
}

for(int i=1;i<=(1<<n);i++){
	int sum=-1,cnt=0 ;
	for(int j=0;j<n;j++){
		
	if(i&(1<<j)){
		cnt++;
		
	}
	
   }
    if(cnt==m){
    for(int j=0;j<n;j++){	
	if(i&(1<<j)){
	sum=a[j]&sum;
   	if(sum>maxn)
   	maxn=sum;	
	}
   	
   }
		}}
	
	
	
	

	
	


	

cout<<maxn;
	
	return 0;
} 
