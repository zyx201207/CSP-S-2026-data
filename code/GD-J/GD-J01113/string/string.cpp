#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(c[i]==c[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]==a[j]){
				i++;j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}else{
			if(a[i]>a[j]){
				ans+=a[i]-a[j];
				a[i]-=a[j];
				j--;
			}else if(a[i]==a[j]){
				i++;j--;
				ans+=a[i];
			}else{
				ans+=a[j]-a[i];
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
