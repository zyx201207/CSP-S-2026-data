#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],p,ans,k=0;
char c[200005];
map<long long,char> m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++)m[j+k]=c[i];
		k+=a[i];
	}
	for(int i=1;i<=k/2;i++){
		if(m[i]!=m[k+1-i]){
			ans++;
		}
	}
//	for(int i=1;i<=n;i++)cout<<c[i];
	cout<<ans;
	return 0;
}
