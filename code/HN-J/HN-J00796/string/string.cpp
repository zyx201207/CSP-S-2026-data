#include<bits/stdc++.h>
using namespace std;
long long n,a[2000005],ans;
char c[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=n,j=1;i>j;){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j++;
			}else if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i--;
			}else{
				ans+=a[i];
				i--;
				j++;
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j++;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i--;
			}else{
				i--;
				j++;
			}
		}
	}
	cout<<ans;
	cout<<endl;
	return 0;
}

