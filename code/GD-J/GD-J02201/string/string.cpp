#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c[250000];
	int n,a[250000];
	long long l=0,ans=0,xi=0,xj=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	int i=1,j=n;
	xi=a[1];xj=a[n];
	while(1){
		if(a[i]>=a[j]){
			if(c[i]!=c[j])ans+=a[j];
			a[i]-=a[j];
			a[j]=0;j--;
			if(a[i]==0)i++;
		}else{
			if(c[i]!=c[j])ans+=a[i];
			a[j]-=a[i];
			a[i]=0;i++;
		}
		if(i>=j)break;
	}
	cout<<ans;
	return 0;
}
