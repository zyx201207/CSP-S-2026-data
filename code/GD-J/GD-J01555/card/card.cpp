#include<bits/stdc++.h>
using namespace std;
long long n,m,fd_,ans[300005],A,a[500005],len=0,d[500005];
bool B=true,b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>1&&(a[i]<a[i-1])){
			B=false;
		}
	}
	if(true){
		for(int i=1;i<=n;i++){
			len=0;
			for(int j=i;j<=n;j++){
				for(int k=0;k<len;k++){
					if(d[k]==a[j]){
						len=k;
						break;
					}
				}
				d[len++]=a[j];
			}
			if(!B){
				sort(d,d+len);
			}
			for(int j=1;j<len;j++){
				if(d[j]==d[j-1]){
					d[j]=300003;
				}
			}
			for(int k=0;k<len;k++){
				ans[d[k]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
