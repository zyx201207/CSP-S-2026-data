#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,x1,x2,f[N],s[N],ans,sum,x;
char c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	scanf("%lld",&n);
	if(n==1){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&x,&c);
		f[i]=x;
		s[i]=c-'a';
	}
//	for(int i=1;i<=n;i++){
//		cout<<f[i]<<" "<<s[i]<<"\n"; 
//	}
	int l=1,r=n;
	while(l<r){
		x1=f[l]-f[r];
		x2=f[r]-f[l];
		if(s[l]!=s[r]){
			if(x1<=0){
				ans+=f[l];
			}	
			else{
				ans+=f[r];
			}
		}
		if(x1<=0){
			f[r]=x2;l++;
		}
		if(x2<=0){
			f[l]=x1;r--;
		} 
		continue ;	
	}
	
	printf("%lld",ans);
	return 0;
}
