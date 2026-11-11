#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200010],c;
ll x;
string s,w;
string t[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>t[i];
		s+=t[i];
	}
	w=s;
	reverse(w.begin(),w.end());
	if(w==s){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n/2;i++){
		if(t[i]!=t[n-i+1]){
			if(a[i]<=a[n-i+1]){
				c+=a[i];
			}else if(a[i]>a[n-i+1]){
				c+=a[n-i+1];
			}
			x=abs(a[i]-a[n-i+1]);
		}else if(a[i]!=a[n-i+1]){
			x=abs(a[i]-a[n-i+1]);
		}else if(x>0){
			c+=x;
			x=0;
		}
	}
	if(x!=0&&n%2==1){
		c+=x;
	}
	cout<<c;
	return 0;
}
