#include<bits/stdc++.h>
using namespace std;
#define int long long
//priority_queue<greater<int>> q;
const int N=5e6+10;
int n,m;
int a[N];
int ans=1;
int j=1,i=1,cnt=0,sum=0,nowq=0;
int xut=0;
int nowp;
bool falt=true;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a+1,a+1+n);
	nowq=1;
	cnt=1;
	sum=0;
	while(i<=n) {
		falt=true;
		while((sum+abs(a[i+1]-a[nowq]))<=m&&i+1<=n){
			falt=false;
			i++;
			sum+=abs(a[i]-a[nowq]);
			cnt++;
			ans=max(ans,cnt);
//			
		}
//		cout<<nowq<<" 1 ";
		if(i==n&&falt==true) break;
		if(falt==true&&i==j){
			i++,j++,nowq++; 
			continue;
		} 
		if(falt==true&&j+1<=i&&j==nowq){
			sum-=abs(a[nowq+1]-a[nowq])*(i-j);
			j++,cnt--,nowq++;
		}
		if(falt==true&&j+1<=i){
//			cout<<1;
			cnt--;
			sum-=abs(a[nowq]-a[j]);
			j++;
			
		}
		if(nowq==i) continue;
		if(i==j){
			nowq=i,sum=0;
			continue;
		}
		if(i==j+1){
			nowq=j,sum=abs(a[j+1]-a[i]);
			continue;
		}
//		nowp=(i+j)/2+1;
//		sum=0;
//		for(int k=j;k<=i;k++) {
//			sum+=abs(a[k]-a[nowq]);
//		}
		nowp=nowq+1;
		xut=sum+abs(a[nowp]-a[nowq])*abs(nowp-j)-abs(a[nowp]-a[nowq])*abs(i-nowp+1);
		while(xut<=sum&&nowp<=n){
			nowq++;
			sum=xut;
			nowp=nowq+1;
			xut=sum+abs(a[nowp]-a[nowq])*abs(nowp-j)-abs(a[nowp]-a[nowq])*abs(i-nowp+1);
		}
	}
	printf("%lld",ans);
	/*
5 5
1 2 4 8 9
*/
	return 0; 
}
 
