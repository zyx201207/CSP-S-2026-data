#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
char a[N],b[N],c[N],y[N];
int x[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int t,g=1,cnt=0,ans=0,len=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>x[i];
		cin>>y[i];
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=x[i];j++){
			a[len+j]=y[i];
		}
		len+=x[i];
	}
	int lb,lc;
	if(len%2==0)lb=len/2;
	else lb=(len-1)/2;
	for(int i=1;i<=lb;i++){
		b[i]=a[i];
	}
	for(int i=len;i>=(len-1)/2+2;i--){
		c[++cnt]=a[i];
	}
	for(int i=1;i<=lb;i++){
		if(b[i]!=c[i])ans++;
	}
	cout<<ans; 
	return 0;
} 
