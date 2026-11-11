#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=2e5+5;
ll n,l;
ll a[N];
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		l+=a[i];
	}
	ll ans=0;
	ll i2=a[1],j2=a[n];
	for(ll i=1,j=l,i1=1,j1=n;i<j&&i1<=j1;){
		if(i2==j2){
			if(c[i1]!=c[j1]){
				ans+=i2;
			}
			i+=i2,j-=i2;
			i1++,j1--;
			i2=a[i1],j2=a[j1];
		}else if(i2>j2){
			if(c[i1]!=c[j1]){
				ans+=j2;
			}
			i+=j2,j-=j2;
			j1--;
			i2-=j2,j2=a[j1];
		}else if(j2>i2){
			if(c[i1]!=c[j1]){
				ans+=i2;
			}
			i+=j2,j-=j2;
			i1--;
			j2-=i2,i2=a[i1];
		}
	}
	cout <<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
