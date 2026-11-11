#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long i=1,j=n;
	while(i<=j){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				ans+=a[j];
				i--;
			}else if(a[j]>a[i]){
				a[j]-=a[i];
				ans+=a[i];
				j++;
			}else{
				ans+=a[i];
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				i--;
			}else if(a[j]>a[i]){
				a[j]-=a[i];
				j++;
			}
		}
		i++,j--;
	}
	cout<<ans;
	return 0;
}
