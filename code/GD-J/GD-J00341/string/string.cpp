#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long sum[200005],ans; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	long long i=1,j=n,l1=a[1],l2=a[n],mn=0,s=1,s2=0,m=(sum[n]+1)>>1;
	while(s<=m&&i<j){
		s2=sum[n]-s+1;
		mn=min(l1,l2);
		//cout<<i<<' '<<j<<' '<<l1<<' '<<l2<<' '<<mn<<' '<<s<<' '<<s2<<' '
		//<<sum[i]<<' '<<sum[j-1]<<' '<<sum[j]<<' '<<ans<<'\n';
		l1-=mn,l2-=mn;
		s+=mn;
		if(c[i]!=c[j])ans+=mn;
		if(s>sum[i])i++,l1=sum[i]-s+1;
		if(s2-mn<=sum[j-1])l2=sum[j-1]-sum[j-2],j--;
		//cout<<l1<<' '<<l2<<'\n';
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
