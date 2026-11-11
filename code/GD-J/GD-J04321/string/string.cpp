#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
char c[200005];
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n,f=0;;
	while(i<j){
		if(c[i]!=c[j])f=1;
		if(a[i]<a[j]){
			a[j]-=a[i];
			a[i]=0;
			ans+=a[j]*f;
			i++;
		}else if(a[j]<a[i]){
			a[i]-=a[j];
			a[j]=0;
			ans+=a[i]*f;
			j--;
		}else{
			ans+=a[i]*f;
			a[i]=0;
			a[j]=0;
			i++;
			j--;
		}
		f=0;
	}
	cout<<ans;
}
