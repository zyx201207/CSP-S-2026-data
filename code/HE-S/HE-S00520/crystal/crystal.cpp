#include<bits/stdc++.h>
using namespace std;
long n,minid;
long long m,a[500025],b[500025],vis[500025],min1=0x3f,ans=0;
bool cmp(long x,long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	scanf("%lld",&m);
	for(long long i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1,cmp);
	long long mid=(n+1)/2;
	for(long long i=1;i<=n;i++){
		if(a[i]==a[mid]){
			ans++;
		}
	}
	for(long long i=1;i<=n;i++){	
		for(long long j=1;j<=n;j++){
			b[j]=a[mid]-a[j];
			if(b[j]<0){
				b[j]*=-1; 
			}
			if(j!=mid){
				if(min1>b[j]&&vis[j]==0){
					min1=b[j];
					minid=j;
				}			
			} 
			if(m>=b[minid]){
				ans++;
				a[j]+=b[minid];
				m-=b[minid];
				vis[minid]=1;
			}else{
				break;
			}	
		}
	}
	printf("%lld\n",ans);
	return 0;
}
