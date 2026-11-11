#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0,ans=0;
	long long m[200010];
	char c[200010];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&m[i],&c[i]);
		sum+=m[i];
	}
	int j=n;
	long long i=0;
	for(int ia=1;i<sum/2;ia++){
		long long cnt =m[ia];
		i+=cnt;
		while(cnt>0){
			if(cnt>=m[j]){
				cnt-=m[j];
				if(c[ia]!=c[j])ans+=m[j];
				j--;
			}else{
				m[j]-=cnt;
				if(c[ia]!=c[j])ans+=cnt;
				cnt=0;
			}
		}
	}
	printf("%lld",ans);
	return 0;
 } 
