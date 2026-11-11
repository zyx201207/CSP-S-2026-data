#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,sum;
ll a[200005];
char c[200005];
map<char , ll > m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(ll i=1,j=n;i<j;){
		if(c[i]==c[j]){
			if(a[i]>a[j]) a[i]-=a[j],j--;
			else if(a[i]<a[j]) a[j]-=a[i],i++;
			else if(a[i]==a[j]) i++,j--;
		}else{
			if(a[i]>a[j]) sum+=a[j],a[i]-=a[j],j--;
			else if(a[i]<a[j]) sum+=a[i],a[j]-=a[i],i++;
			else if(a[i]==a[j]) sum+=a[i],i++,j--;
		}
	}
	cout<<sum;
	return 0;
}
