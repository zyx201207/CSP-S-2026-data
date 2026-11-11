#include<bits/stdc++.h>
using namespace std;
long long n;
long long siz;
long long sum;
long long ans;
long long a[200005];
char b[200005];
long long x,y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
    	siz+=a[i];
	}
	long long i,j,k,l;
	for(i=1,j=n,k=0,l=siz+1;k<l,i<j;k+=ans,l-=ans){
		if(a[i]<=a[j]) ans=a[i];
		else ans=a[j];
		if(b[i]!=b[j]) {
		   sum+=ans;
		}
		a[i]-=ans;
		a[j]-=ans;
		if(a[i]==0) i+=1;
		if(a[j]==0) j-=1;
	}
	cout<<sum;
	return 0;
}
