#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int w[N],k[N];
int n,m;
int ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",%k[i]);
		for(int j=1;j<=2*k[i];j+=2){
			
		}
	}
	ans=1;
	int c=n;
	for(int i=1;i<=c;i++){
		for(int j=i;j<n;j++){
			b[j+1]=b[j]+(a[j+1]-a[j])*(j-i+1);
			if(b[j+1]>m){
				ans=max(ans,j-i+1);
				c=n-ans;
				break;
			}
			b[j]=0;
			
		}
		b[n]=0;
		
	}
	cout<<ans;
	
	return 0;
}
