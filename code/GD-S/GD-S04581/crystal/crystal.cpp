#include<bits/stdc++.h>
using namespace std; 
long long n,m,a[514514],l=n-1,ans=0,cnt,mcnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cnt=1;
		mcnt=m;
		for(int j=i-1;j>=0;j--){
			if(a[j]==a[i]){
				l=j;
				cnt++;
			}
			else{
				if(a[i]-a[j]<=mcnt){
					mcnt-=a[i]-a[j];
					cnt++;
				}
				else{
					break;
				}
			}
		}
		ans=max(ans,cnt);
		i=l;
	}
	printf("%lld",ans);
}
