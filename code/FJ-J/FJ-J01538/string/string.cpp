#include<bits/stdc++.h>
using namespace std;
long long n,a[212345],ans=0;
char c[212345];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	long long i=1,ii=a[1],j=n,jj=a[n];
	while(1){
		bool p=0;
		if(c[i]!=c[j])p=1;
		if(ii>jj){
			if(p)ans+=jj;
			ii-=jj;
			jj=0;
		}
		else{
			if(p)ans+=ii;
			jj-=ii;
			ii=0;
		}
		
		
		if(ii==0){
			i++;
			ii=a[i];
		}
		if(jj==0){
			j--;
			jj=a[j];
		}
		if(i>=j)break;
	}
	cout<<ans;
	return 0;
}

