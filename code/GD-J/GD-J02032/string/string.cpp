#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	char s[200005];
	long long ans=0,num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		num+=a[i];
	}
	a[0]=0;
	long long l=0,r=a[n],m=0,j=n;
	bool f=false;
	for(int i=1;i<=n;i++){
		l+=a[i-1];
		m+=a[i];
		if(m>=num/2){
			m=num/2;
			f=true;
		}
		while(r<=m&&j>0){
			if(s[j]!=s[i]) ans+=a[j];
			j--;
			r+=a[j];
		}
		if(s[j]!=s[i]) ans=ans+m-r+a[j];
		a[j]=a[j]-m+r-a[j];
		if(f) break;
	}
	cout<<ans;
	return 0;
} 
