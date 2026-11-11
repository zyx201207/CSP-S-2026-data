#include<iostream>
#include<algorithm>
using namespace std;
int n,m,cnt=1,a[500008],b[500008];
int s,d;
int xc(int q,int w){
	if(q<w)
	return 0;
	int zx=0;
	for(int c=w;c>=1;c--){
	    zx+=b[q-c+1]*c;
	    if(zx>m)
	        return 0;}
	return 1;}
	
int sdf(int x){
	int j=cnt+1;
	while(xc(x,j)==1){
		j+=1;}
	return j-1;}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];}
	
	for(int i=n;i>1;i--){
		//到达i最多有几个
		cnt=max(cnt,sdf(i)); 
	}
	cout<<cnt;

	return 0;
}

