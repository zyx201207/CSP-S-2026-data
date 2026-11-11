#include<bits/stdc++.h>
using namespace std;
int a[200005],n,lnow=0,rnow,ly=0,ry=0,now;
long long s,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	rnow=n-1;
	for(int i=0;i<n;++i){
		scanf("%d %c",&a[i],&c[i]);
		s+=a[i];
	}
	s=s/2+s%2;
	for(long long i=0;i<s && lnow!=rnow;){
		now=(a[lnow]-ly)-(a[rnow]-ry); 
//		cout<<lnow<<" "<<rnow<<" "<<i<<endl; 
		if(c[lnow]==c[rnow]){
			if(now>0){
				i+=a[rnow]-ry;
				ly=a[lnow]-now;
				ry=0;
				rnow-=1;
			}
			else if(now<0){
				i+=a[lnow]-ly;
				ry=a[rnow]+now;
				ly=0;
				lnow+=1;
			}
			else{
				i+=a[lnow]-ly;
				ly=0;
				ry=0;
				lnow+=1;
				rnow-=1;
			}
		}
		else{
			if(now>0){
				i+=a[rnow]-ry;
				ans+=a[rnow]-ry;
				ly=a[lnow]-now;
				ry=0;
				rnow-=1;
			}
			else if(now<0){
				i+=a[lnow]-ly;
				ans+=a[lnow]-ly;
				ry=a[rnow]+now;
				ly=0;
				lnow+=1;
			}
			else{
				i+=a[lnow]-ly;
				ans+=a[lnow]-ly;
				ly=0;
				ry=0;
				
				lnow+=1;
				rnow-=1;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

