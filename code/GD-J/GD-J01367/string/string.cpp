#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0;
	cin>>n;
	char s[1000000000],y[n];
	long long x[n],x2[n],m1,m2,m,ans=0;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		l+=x[i];
		x2[i]=l;
	}if(l%2){
		for(int i=0;i<n;i++){
			if(x2[i]>=l/2+1){
				m2=x2[i]-l/2-1;
				m1=x[i]-m2;
				m=i;
				break;
			}
		}
	}else{
		for(int i=0;i<n;i++){
			if(x2[i]>=l/2){
				m2=x2[i]-l/2;
				m1=x[i]-m2;
				m=i;
				break;
			}
		}
	}for(int i=0;i<=m;i++){
		if(y[i]!=y[n-i-1]){
			ans+=min(x[i],x[n-i-1]);
			if(x[i]>x[n-i-1]){
			if(y[i]!=y[n-i-2]&&(n-i-2)>=m)ans+=x[i]-x[n-i-1];
			if(y[i]==y[n-i-2]&&(n-i-2)>=m)x[n-i-2]-=x[i]-x[n-i-1];
		}else if(x[i]<x[n-i-1]){
		 	if(y[i+1]!=y[n-i-1]&&(i+1)<m)ans+=x[n-i-1]-x[i];
		 	if(y[i+1]==y[n-i-1]&&(i+1)<m)x[i+1]-=x[n-i-1]-x[i];
		}
		}if(y[i]==y[n-i-1]){
		if(x[i]>x[n-i-1]){
			if(y[i]!=y[n-i-2]&&(n-i-2)>=m)ans+=x[i]-x[n-i-1];
			if(y[i]==y[n-i-2]&&(n-i-2)>=m)x[n-i-2]-=x[i]-x[n-i-1];
		}else if(x[i]<x[n-i-1]){
		 	if(y[i+1]!=y[n-i-1]&&(i+1)<m)ans+=x[n-i-1]-x[i];
		 	if(y[i+1]==y[n-i-1]&&(i+1)<m)x[i+1]-=x[n-i-1]-x[i];
		}
			
		}
	}
	cout<<ans;
	return 0;
}
