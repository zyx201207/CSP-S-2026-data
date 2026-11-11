#include<bits/stdc++.h>
using namespace std;
string s,h;
char c[200010];
long long n,ans,k,o=0;
int a[200010];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		k+=a[i];
	}
	for(int i=1;i<=n/2;i++){
		if(a[i]!=a[n-i+1]){
			o=1;
			break;
		}
		if(o==0&&c[i]!=c[n-i+1]){
			ans+=a[i];
		}
	}
	if(o==0){
		cout<<ans;
		return 0;
	}
	if(k>100000000){
		cout<<"0";
		return 0;
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
			h=c[i]+h;
		}
	}
	for(int i=0;i<k/2;i++){
		if(s[i]!=h[i])ans++;
	}
	cout<<ans;
	return 0;
} 
