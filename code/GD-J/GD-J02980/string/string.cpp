#include<iostream>
#define N 200010
using namespace std;
int n,a[N];
long long ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=j;i++){
		while(a[i]>=a[j]){
			a[i]-=a[j];
			if(c[i]!=c[j])ans+=a[j];
			j--;
		}
		a[j]-=a[i];
		if(c[i]!=c[j])ans+=a[i];
	}
	cout<<ans;
	return 0;
}
