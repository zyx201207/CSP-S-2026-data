#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,l,r,cl,cr;
ll a[200005],k[200005],ans,aan;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		k[i]=a[i];
	}
	l=1,r=n;
	cl=a[1],cr=a[n];
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r]){
			if(c[l]!=c[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		else{
			if(c[l]!=c[r]) ans+=a[l];
			r--,l++;
		}
	}
	cout<<ans;
	return 0;
}
