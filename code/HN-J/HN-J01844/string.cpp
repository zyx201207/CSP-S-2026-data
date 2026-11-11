#include<bits/stdc++.h>
using namespace std; 
int n,ans=0;
long long l;
long long s[200005];
char z[200005];
int main(){
	freopen("string.in",r,stdin);
	freopen("string.out",w,stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>z[i];
		l+=s[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i]+s[i-1];
	}
	s[0]=1;
	for(long long i=1;i<=l/2;i++){
		char d;
		int h;
		for(int j=1;j<=n;j++){
			if(i<=s[j]){
				d=z[j];
				break;
			}
		}
		h=l+1-i;
		char d1;
		for(int j=1;j<=n;j++){
			if(h<=s[j]){
				d1=z[j];
				break;
			}
		}
		if(d!=d1){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
