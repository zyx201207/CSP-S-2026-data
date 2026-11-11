#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long n,a[maxn],l,r,sum[maxn],ans;
char c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1,j=n;i<j;)
		if(a[i]-l<=a[j]-r){
			r+=a[i]-l;
			if(c[i]!=c[j])ans+=a[i]-l;
			l=0;
			i++;
		}else{
			l+=a[j]-r;
			if(c[i]!=c[j])ans+=a[j]-r;
			r=0;
			j--;
		}
	cout<<ans<<'\n';
	return 0;
}
