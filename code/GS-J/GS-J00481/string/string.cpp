#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005],x[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<=a[i];j++){
			x[j]+=c[i]; 
		}
	}
	for(int i=0,j=n;i<=n/2,j>=n/2;i++,j--){
		if(x[i]!=x[j]){
			x[i]=x[j];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
