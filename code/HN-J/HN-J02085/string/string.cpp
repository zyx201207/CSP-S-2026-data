#include<bits/stdc++.h>
using namespace std;
int n,a[200005];char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	long long l=0,r=0,x=1,y=n,ans=0;
	char cl='1',cr='1';
	while(x<=y){
		if(l>r){
			r+=a[y];
			cr=c[y];
			if(cl!=cr){
//				cout<<l<<" "<<r<<" "<<y<<" ";
				if(r>=l){
					ans+=(l-r+a[y]);
				}
				else {
					ans+=(a[y]);
				}
			}y--; 
		} 
		else{
			l+=a[x];
			cl=c[x]; 
			if(cl!=cr){
				if(l>=r){
					ans+=(r-l+a[x]);
				}
				else {
					ans+=(a[x]);
				}
			}x++;
		} 
	}
	cout<<ans;
	return 0;
}
//3
//2 a
//2 b
//1 c
