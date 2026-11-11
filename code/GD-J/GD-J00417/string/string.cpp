#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		b[i]=c-'a';
	}
	long long i=1,j=n,l=a[1],r=a[n],las=0,ans=0;
	while(i<j){
		if(l==r){
			if(b[i]!=b[j]){
				ans+=(l-las);
			}
			++i,--j,las=l,l+=a[i],r+=a[j];
		}else if(l<r){
			if(b[i]!=b[j]){
				ans+=(l-las);
			}
			++i,las=l,l+=a[i];
		}else{
			if(b[i]!=b[j]){
				ans+=(r-las);
			}
			--j,las=r,r+=a[j];
		}
	}
	cout<<ans;
	return 0;
}
