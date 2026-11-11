#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL n,m,a[N];
bool flag[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(flag,0,sizeof(flag));
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	LL sum=0;
	for(int i=30;i>=0;i--){
		LL t=1,cnt=0;
		for(int j=1;j<=i;j++) t*=2;
		for(int j=1;j<=n;j++){
			if(!flag[j]&&a[j]>=t) cnt++;
		}	
		if(cnt>=m){
			sum+=t;
			for(int j=1;j<=n;j++){
				if(!flag[j]&&a[j]<t) flag[j]=1;
				else if(!flag[j]) a[j]-=t;
			}	
		}	
	}	
	cout<<sum;
	return 0;
}
