#include<bits/stdc++.h>
using namespace std;
#define int long long
long long ans;
int n,a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j]){
			if(a[i]>a[j])ans+=a[j],a[i]-=a[j],j--;
			else{
				if(a[j]>a[i])ans+=a[i],a[j]-=a[i],i++;
				else ans+=a[i],i++,j--;
			}
			//cout<<c[i]<<":"<<a[i]<<"\n"<<c[j]<<":"<<a[j]<<"\n";
		}
		else{
			if(a[i]>a[j])a[i]-=a[j],j--;
			else a[j]-=a[i],i++;
		}
	}
	cout<<ans;
	return 0;
}
