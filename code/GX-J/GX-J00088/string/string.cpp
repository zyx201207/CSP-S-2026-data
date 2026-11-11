#include <iostream>
using namespace std;
long long n,ans;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=1;i<=n/2;){
		for(long long j=n;j>i;){
			if(c[i]!=c[j]){
				if(a[i]>a[j]){
					ans+=a[j];
					a[i]-=a[j];
					j--;
				}
				else if(a[i]<a[j]){
					ans+=a[i];
					a[j]-=a[i];
					i++;
				}
				else{
					ans+=a[i];
					i++;
					j--;
				}
			}
			else{
				if(a[i]>a[j]){
					a[i]-=a[j];
					j--;
				}
				else if(a[i]<a[j]){
					a[j]-=a[i];
					i++;
				}
				else{
					i++;
					j--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
