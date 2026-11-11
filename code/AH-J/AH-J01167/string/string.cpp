#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	long long i=0,j=n-1;
	while(i<=j){
		if(c[i]!=c[j]){
			if(a[i]==a[j]){
				ans+=a[i];
				i++;
				j--;
			}else if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}else{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
		}else{
			if(a[i]==a[j]){
				i++;
				j--;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
