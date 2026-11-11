#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a[200010],n,z=0,c=1;
	char b[200010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(c<=n){
		if(b[c]!=b[n]){
			if(a[c]<a[n]){
				z+=a[c];
				a[n]-=a[c];
				c++;
			}else if(a[c]==a[n]){
				z+=a[c];
				c++;
				n--;
			}else{
				z+=a[n];
				a[c]-=a[n];
				n--;
			}
		}else{
			if(a[c]<a[n]){
				a[n]-=a[c];
				c++;
			}else if(a[c]==a[n]){
				c++;
				n--;
			}else{
				a[c]-=a[n];
				n--;
			}
		}
	}
	cout<<z;
	return 0;
} 
