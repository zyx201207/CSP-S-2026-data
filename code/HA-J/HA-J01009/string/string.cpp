#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	ll ans=0;
	ll i=1,j=n;
	while(i<j){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]=a[i]-a[j];
				j--;
			}else if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}else{
				ans+=a[i];
				i++;
				j--;
			}
		}else{
			if(a[i]>a[j]){
				a[i]=a[i]-a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

