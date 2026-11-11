#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],s,f,mx;
void d(long long c,int x,int w){
	if(x==m+1){
		s=max(s,c);
		return;
	}
	for(int i=w+1;i<=n-m+1+x;i++){
		d(a[i]&c,x+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i!=1)f&=a[i];
		else f=a[1];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+1+n,greater<int>());
	if(m==n){
		printf("%lld",f);
		return 0;
	}
	if(m==1){
		printf("%lld",a[1]);
		return 0;
	}
	if(m==2){
		long long q=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				q=max(q,a[i]&a[j]);
			}
		}
		printf("%lld",q);
		return 0;
	}
	if(mx<4||m==n-1){
		int u=a[1];
		for(int i=2;i<=m;i++){
			u&=a[i];
		}
		printf("%d",u);
		return 0;
	}
	if(mx<pow(2,20)){
		s=a[1];
		for(int i=2;i<=m;i++){
			s&=a[i];
		}
		printf("%lld",s);
		return 0;
	}
	for(int i=1;i<=n-m+1;i++)
		d(a[i],1,i);
		
	printf("%lld",s); 
	return 0;
}
