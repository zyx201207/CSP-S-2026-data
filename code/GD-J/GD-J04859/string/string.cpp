#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,ans;
int a[N],c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char cc;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>cc;c[i]=cc-'0'+1;
	}
	int i=1,j=n;
	while(1){
		if(i==j&&c[i]==c[j])break;
		if(a[i]>a[j]){
			if(c[i]!=c[j])ans+=a[j];
			a[i]-=a[j];
			j--;
		}else if(a[i]<=a[j]){
			if(c[i]!=c[j])ans+=a[i];
			a[j]-=a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}
