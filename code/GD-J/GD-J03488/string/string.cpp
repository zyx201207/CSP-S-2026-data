#include<bits/stdc++.h>
using namespace std;
long long n,x,ans,n1=1,a[200005];
char c;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>c;
		while(x--)a[n1]=c-'0',n1++;
	}
	for(long long i=1,j=n1-1;i<=n1/2;i++,j--){
		if(a[i]!=a[j])ans++;
	}
	cout<<ans;
	return 0;
} 
