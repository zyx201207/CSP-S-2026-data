#include<bits/stdc++.h>
using namespace std;
long long n,l,r,a[211111],s;
char c[211111]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	while(l<r){
		if(a[l]<a[r]){
			if(c[l]!=c[r])s+=a[l];
			a[r]-=a[l];
			l++;
		}
		else{
			if(c[l]!=c[r])s+=a[r];
			a[l]-=a[r];
			r--;
		}
	}
	cout<<s;
	return 0;
} 
