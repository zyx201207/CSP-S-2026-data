#include<bits/stdc++.h>
using namespace std;
int main(){
	freoprn("string.in","r",stdin);
	freoprn("string.out","w",stdout);
	long long n,ans=0,a[200005];
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long i=1,j=n;
	while(i<j){
		if(c[i]!=c[j]){
			if(a[i]<a[j]){
				a[j]-=a[i];
				ans+=a[i];
				i++;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				ans+=a[j];
				j--;
			}else{
				ans+=a[i];
				i++;
				j--;
			}
		}else{
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
