#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e7+5;
long long n,len=1,a[N],ans=0;
char c[N],sum[M];
bool f=1,flag=1; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n==1){
		cout<<"1";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[len]=c[i];
		if(c[i]!=c[i-1]&&i>=2)f=0;
		len+=a[i];
	}
	if(f==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=(n+1)/2;i++){
		if(a[i]!=a[n-i+1]||c[i]!=c[n-i+1])flag=0;
		
	}
	for(int i=1;i<len;i++){
		if(sum[i]==0)sum[i]=sum[i-1];
	}
	if(flag==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=(len+1)/2;i++){
		if(sum[i]!=sum[n-i+1])ans++;
	}
	cout<<ans;
}
