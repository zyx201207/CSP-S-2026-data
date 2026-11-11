#include<bits/stdc++.h>
using namespace std;
long long a[500005];
char c[5000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	} 
	for(long long i=1,j=n;i<=j;){
		if(c[i]!=c[j]) ans+=min(a[i],a[j]);
		if(a[i]==a[j]){
			i++;
			j--;
		}
		else if(a[i]<a[j]){
			a[j]-=a[i];
			i++;
		}
		else{
			a[i]-=a[j];
			j--;
		}
	}
	cout<<ans;
	return 0;
}

