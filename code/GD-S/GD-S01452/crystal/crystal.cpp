#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
int n,sum=0;
long long m,a[N],chazhi;
bool tepan=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		if(i==2) chazhi=a[2]-a[1];
		if(i>2) if(a[i]-a[i-1]!=chazhi) tepan=false;
	}
	sort(a+1,a+n+1,greater<long long>());
	if(tepan){
		for(int i=1;i<=n&&m>0;i++){
			if(a[1]-a[i]<=m){
				sum++;
				m-=a[1]-a[i];
			}
		}
		printf("%d",sum);
		return 0;
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		long long mm=m;
		for(int j=i;j<=n&&mm>0;j++){
			if(a[i]-a[j]<=mm){
				ans++;
				mm-=a[i]-a[j];
			}
		}
		sum=sum>ans?sum:ans;
	}
	printf("%d",sum);
	return 0;
} 
