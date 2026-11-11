#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN=2E5+5;

int n,m,a[MAXN],max1;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		max1=max(max1,a[i]);
	}
	sort(a+1,a+n+1);
	if(m==1){
		printf("%d",a[n]);
		return 0;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%d",ans);
		return 0;
	}else if(m==n||m==n-1){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		if(m==n){
			printf("%d",ans);
		}else{
			int now=0,zans=0;
			string ns="";
			while(ans){
				ns=char((!(ans%2)))+ns;
				ans/=2;
			}
			for(int i=0;i<ns.size();i++){
				now+=(1<<i)*ns[i]-'0';
			}
			for(int i=1;i<=n;i++){
				zans=max(zans,now^a[i]);
			}
			printf("%d",zans);
		}
		return 0;
	}
	printf("%d",a[n-m+1]);
	return 0;
} 
