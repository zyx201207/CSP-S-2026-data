#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];	
char c[200005];
ll n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			a[i-1]+=a[i];
			n--;
			i--;
		}
	}
	int j = n-1;
	for(int i = 0;i<=j;){
		if(a[i]>a[j]){
			if(c[i]==c[j]){
				a[i]-=a[j];
				j--;
			} else{
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
		}else{
			if(c[i]==c[j]){
				a[j]-=a[i];
				i++;
			}else{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
