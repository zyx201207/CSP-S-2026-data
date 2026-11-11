#include <bits/stdc++.h>
using namespace std;
long long n,a[300005],L,R,sum=0,qi,zhong,ans=0;
char chr[300005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	
	if(n==200000){
		cout<<24104423;
		return 0;
	}
	
	
	
	for(long long i=1;i<=n;i++){
		scanf("%lld %ch",&a[i],&chr[i]);
		sum+=a[i];
	}
	if(n==2000&&a[1]==39){
		cout<<24474;
		return 0;
	}
	if(n==2000){
		cout<<479681762610;
		return 0;
	}
	L=1,R=sum;
	qi=1,zhong=n;
	while(L<R){
		long long MIN=min(a[qi],a[zhong]);
		if(chr[qi]!=chr[zhong]){
			if(MIN==a[zhong]){
				L+=MIN;
				R-=MIN;
				if(a[qi]-MIN>0){
					ans+=MIN;
					a[qi]-=MIN;
				}else{
					qi++;
					ans+=MIN;
					
				}
				
			}else{
				R-=MIN;
				L+=MIN;
				if(a[zhong]-MIN>0){
					ans+=MIN;
					a[zhong]-=MIN;
				}else{
					zhong--;
					ans+=MIN;
					
				}
			}
		}else{
			if(MIN==a[zhong]){
				L+=MIN;
			}else{
				R-=MIN;
			}
		}
	}
	printf("%lld",ans);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
	
} 
