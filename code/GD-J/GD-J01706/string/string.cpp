#include<bits/stdc++.h>
using namespace std;
long long int n,a[10000001],sum=0;
char c[10000001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=sum;j<a[i]+sum;j++){
			s[j]=c[i];
		}
		sum+=a[i];
	}
	int ans=0;
	for(int i=0,j=sum-1;i<sum/2,j>sum/2;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
