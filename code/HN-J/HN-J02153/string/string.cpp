#include <bits/stdc++.h>
using namespace std;
long long n,k,cnt,cnt1;
char c[200010],c1[200010];
long long a[200010];

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		k+=a[i];
		int l=1;
		for(int j=1;j<=k;j++){
			c1[j]=c[l];
			if(j>a[j]) l++;
		} 
	}
	for(int i=1;i<=n;i++){
		if(c[i]==c[i+1]){
			cnt++;
		}
		if(cnt==n-1){
			cout<<0;
			return 0;
		}
	}
	long long d1[200010];
	if(k%2==0){
		for(int i=1;i<=k/2;i++){
			d1[i]=c1[i];
		}
		for(int i=(k/2)+1;i<=k;i++){
			if(c1[i]!=d1[i]){
				cnt1++;
			}
		}
	}else if(k%2!=0){
		for(int j=1;j<=(k-1)/2;j++){
			d1[j]=c1[j];
		}
		for(int j=(k-1)/2;j<=k;j++){
			if(c1[j]!=d1[j]){
				cnt1++;
			}
		}
	}
	cout<<cnt1;
	return 0;
}
