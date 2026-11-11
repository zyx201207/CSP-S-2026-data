#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int j=n,gl=0;
	for(int i=1;i<=n;i++){
		while(i<j&&a[j]-gl<=a[i]){
			if(c[j]!=c[i])ans+=a[j]-gl;
			a[i]-=a[j]-gl;
			j--;
			gl=0;
		}
		if(i==j)break;
		if(c[j]!=c[i])ans+=a[i];
		gl+=a[i];
	}
	cout<<ans;
	return 0;
}
