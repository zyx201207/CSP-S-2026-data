//GZ-S00221 安顺市第一高级中学 张承潇
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=5e5+10;
const ll base=1000000000005;
int n;
ll m;
ll a[maxn];
ll b[maxn];
int f[maxn];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		a[i]+=base;
	}ll Min=a[1]-1;
	for(int i=1;i<=n;i++)
		a[i]-=Min;
		
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++)
		{b[i]=a[i];b[i]+=b[i-1];}
	
	f[1]=1;
	for(int i=1;i<=n;i++){
		if(a[i]*(i-1)-b[i-1]<=m)
			f[i]=i;
		else{
			f[i]=f[i-1];
			for(int j=i-f[i];j>=1;j--){
				if(a[i]*(i-j)-(b[i-1]-b[j-1])<=m)
					f[i]=i-j+1;
				else break;
			} 
		}
	}
	printf("%d",f[n]);
	
	return 0;
}






