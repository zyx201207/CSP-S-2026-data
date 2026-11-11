#include<bits/stdc++.h>
using namespace std;
long long n,cd,l,r,lb,rb,ans,a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cd+=a[i];
	}
	l=1;
	r=cd;
	lb=1;
	rb=n;
	ans=0;
	while(lb<rb){
		if(c[lb]==c[rb]){
			if(a[lb]>a[rb]){
				a[lb]-=a[rb];
				r-=a[rb];
				a[rb]=0;
				rb--;
			}
			else if(a[lb]<a[rb]){
				a[rb]-=a[lb];
				l+=a[lb];
				a[lb]=0;
				lb++;
			}
			else{
				l+=a[lb];
				r-=a[rb];
				a[lb]=0;
				a[rb]=0;
				lb++;
				rb--;
			}
		}
		else{
			if(a[lb]>a[rb]){
				a[lb]-=a[rb];
				ans+=a[rb];
				r-=a[rb];
				a[rb]=0;
				rb--;
			}
			else if(a[lb]<a[rb]){
				a[rb]-=a[lb];
				ans+=a[lb];
				l+=a[lb];
				a[lb]=0;
				lb++;
			}
			else{
				l+=a[lb];
				r-=a[rb];
				ans+=a[lb];
				a[lb]=0;
				a[rb]=0;
				lb++;
				rb--;
			}
		}
	}
	cout<<ans;
	return 0;
}
