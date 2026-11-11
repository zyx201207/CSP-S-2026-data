#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans;
string c[200005];


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	
	int l=1,r=n;
	while(l<=r){
		if(a[r]>a[l]){
			if(c[l]!=c[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		else if(a[r]<a[l]){
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		else{
			if(c[l]!=c[r]) ans+=a[l]; 
			l++;
			r--;
		}
	}
	cout<<ans;
}
