#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll a[200010];
char c[200010];
ll ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(ll i=1,j=n;j>i;){
		if(c[i]==c[j]){
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else if(a[i]==a[j]){
				i++;
				j--;
			}else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
		}
		if(c[i]!=c[j]){
			if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}else if(a[i]==a[j]){
				ans+=a[i];
				i++;
				j--;
			}else if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
		}
	}
	cout<<ans;
	return 0;

}
