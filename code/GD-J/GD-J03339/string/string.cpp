#include<iostream>
using namespace std;
long long a[200000+5];
char c[200000+5];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	int n;cin>>n;for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=n;
	for(int i=1;l-i>=1;){
		if(c[i]==c[l]){
			if(a[i]>a[l]){
				a[i]-=a[l];l--;
			}
			else if(a[l]>a[i]){
				a[l]-=a[i];i++;
			}
			else{
				i++;l--;
			}
		}
		else{
			if(a[i]>a[l]){
				ans+=a[l];a[i]-=a[l];l--;
			}
			else if(a[l]>a[i]){
				ans+=a[i];a[l]-=a[i];i++;
			}
			else{
				ans+=a[i];i++;l--;
			}
		}
	}
	cout<<ans;
}
