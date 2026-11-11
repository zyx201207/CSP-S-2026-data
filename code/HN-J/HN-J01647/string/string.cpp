#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long pd=n,px=a[n],ans=0;
	for(long long i=1;i<=n/2;i++){
		long long cnt=a[i];
		while(1){
			if(c[i]!=c[pd]){
				if(cnt>=px){
					ans+=px;
					cnt-=px;
					if(cnt==0){
						break;
					}
					pd--;
					px=a[pd];
					if(pd<=i){
						cout<<ans;
						exit(0);
					}
				}else{
					px-=cnt;
					ans+=cnt;
					cnt=0;
					break;
				}
			}else{
				if(cnt>=px){
					cnt-=px;
					if(cnt==0){
						break;
					}
					pd--;
					px=a[pd];
					if(pd<=i){
						cout<<ans;
						exit(0);
					}
				}else{
					px-=cnt;
					cnt=0;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

