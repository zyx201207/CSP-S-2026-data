#include<iostream>
#include<algorithm>
using namespace std;
int n,ans=1;
long long m,a[500010],b[500010],c[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
	sort(a+1,a+n+1);
	b[1]=0;
	c[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=abs(a[i]-a[i-1]);
	}
	c[2]=b[2];
	for(int i=2;i<=n;i++){
		c[i]=c[i-1]+b[i];
	}
	for(int i=2;i<=n;i++){
		long long x=0;
		int y=1;
		for(int j=i-1;j>=1;j--){
			if(x+c[i]-c[j]<=m){
				x+=c[i]-c[j];
				y++;
			}
			else{
				break;
			}
		}
		ans=max(ans,y);
	}
	cout<<ans;
	return 0;
   }
   	sort(a+1,a+n+1);
   	long long x=a[2]-a[1];
   	int y=0;
   	if(n%2==0){
   		y=n/2;
	   }
	   else{
	   	y=n/2+1;
	   }
	   for(int i=y-1;i>=1;i--){
	   	if(m-(y-i)*x*2>=0){
	   		ans+=2;
	   		m-=(y-i)*x*2;
	   		continue;
		   }
		   if(m-(y-i)*x>=0){
		   	ans+=1;
			   m-=(y-i)*x;
			   break;
		   }
	   }
	   cout<<ans;
	return 0;
}
