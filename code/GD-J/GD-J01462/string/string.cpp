#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,a[200005],sum=0,ans=0,sumn=0,summ=0,m=0,q=0;
	char b[200005];
	cin>>n;
	if(n%2==0){
		sumn=n/2;
		summ=n/2;
		m=n/2;
		q=n/2+1;
	}else {
		sumn=(n-1)/2;
		summ=(n-1)/2;
		m=n/2+1;
		q=n/2+1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	for(int i=1;m==0&&q==0;i++){
		int j=1;
		int z=0,x=0;
		while(z!=0){
			if(a[m]!=0)z=b[m];
			else m--;
		}
		while(z!=0){
			if(a[q]!=0)x=b[q];
			else q--;
		}
		if(z==x){
			a[m]--;
			a[q]--;
		}else {
			ans++;
			a[m]--;
			a[q]--;
		}
	}
	cout<<ans;
	return 0;
} 
