#include<bits/stdc++.h>
using namespace std;
string a;
char t;
long long n,w[200005],l=1,r,ans,xb1=1,xb2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>t;
		a+=t;
	}
	r=n;
	while(l<=r){
		if(w[l]>w[r]){
			if(a[l-1]!=a[r-1]) ans+=w[r];
			w[l]-=w[r];
			r--;
		}
		else if(w[l]<w[r]){
			if(a[l-1]!=a[r-1]) ans+=w[l];
			w[r]-=w[l];
			l++;
		}
		else if(w[l]==w[r]){
			if(a[l-1]!=a[r-1]) ans+=w[l];
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
