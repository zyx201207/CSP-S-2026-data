#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long s[200005];
long long ans=0;
int k=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
	}
	ans=(s[n]+1)/2;
	bool ok=1;
    for(int i=1;i<=n/2;i++){
    	if(a[i]!=a[n-i+1]||c[i]!=c[n-i+1]){
    		ok=0;
		}
	}
	for(int i=2;i<=n;i++){
		if(c[i]==c[1])
		k++;
	}
	if(k==n-1){
		ok=1;
	}
	long long l=(s[n]+1)/2;
	long long r=(s[n]+1)/2;
	for(long long l=(s[n]+1)/2,r=(s[n]+1)/2;l>=1,r<=s[n];l--,r++){
		int x,y;
		for(int i=0;i<n;i++){
			if(l>=s[i]&&l<=s[i+1]){
				x=i;
			} 
			if(r>=s[i]&&r<=s[i+1]){
				y=i;
			} 
		}
		if(c[x]==c[y]){
			ans--;
		}
    }
	if(ok){
		cout<<0;
	}else{
		cout<<s[n]/2;
	}
	return 0; 
}
