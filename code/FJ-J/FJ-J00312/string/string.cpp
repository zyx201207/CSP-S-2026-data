#include<bits/stdc++.h>
using namespace std;
long long n,j=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n+1];
	char c[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int j=n,i=1;
	while(i<j){
		if(a[j]==a[i]){
			ans+=a[j];
			a[j]=0;
			a[i]=0;
		}
		else if(a[j]>a[i]){
			ans+=a[i];
			a[j]-=a[i];
			a[i]=0;
		}
		else if(a[j]<a[i]){
			ans+=a[j];
			a[i]-=a[j];
			a[j]=0;
		}
		if(a[i]==0){
			i++;
		}
		if(a[j]==0){
			j--;
		}
	}
	cout<<ans;
	return 0;
}