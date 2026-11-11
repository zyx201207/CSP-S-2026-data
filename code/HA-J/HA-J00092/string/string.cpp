#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll ans,n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1,j=n;i<=j;){
		if(a[i]>a[j]){
			a[i]-=a[j];
			if(c[i]!=c[j])ans+=a[i];
			j--;
		}
		else if(a[i]==a[j]){
			if(c[i]!=c[j])ans+=a[j];
			i++;
			j--;
		}
		else {
			a[j]-=a[i];
			if(c[i]!=c[j])ans+=a[j];
			i++;
		}
	}
	cout<<ans;
	return 0;
}









