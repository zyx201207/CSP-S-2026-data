#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int i=1,j=n;
	while(i!=j){
		if(i>=j)break;
		//cout<<i<<" "<<j<<"\n";
		if(a[i]==a[j]){
			if(c[i]!=c[j])ans+=a[i];
			i++;
			j--;
			continue;
		}
		if(a[i]>a[j]){
			a[i]-=a[j];
			if(c[i]!=c[j])ans+=a[j];
			j--;
		}else{
			a[j]-=a[i];
			if(c[i]!=c[j])ans+=a[i];
			i++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
