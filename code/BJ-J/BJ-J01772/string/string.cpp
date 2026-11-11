#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	for(int i=1,j=n;i<=n&&j>=1;){
		if(c[i]!=c[j]) ans+=min(a[i],a[j]);
		if(a[i]>a[j]){
			a[i]-=a[j],a[j]=0,j--;
		}else if(a[i]<a[j]){
			a[j]-=a[i],a[i]=0,i++;
		}else{
			a[i]=0,a[j]=0,i++,j--;
		}
	}
	/*for(int i=1;i<=n;i++){
		if(n%2==1&&i==n/2+1) continue;
		ans+=a[i];
	}*/
	cout<<ans;
	return 0;
}
