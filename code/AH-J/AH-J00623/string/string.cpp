#include<bits/stdc++.h>
using namespace std;
long long const T=2000090010;
long long int n,x,k=1,cnt=0,a,len=0;
char s;
char c[T];
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a;
		len+=a;
		cin>>s;
		for(int j=1;j<=a;j++){
			c[k++]=s;
		}
}
	x=len/2;
	for(int i=1;i<=x;i++){
		if(c[len+1-i]!=c[i]){
			cnt++;
			};
	}	
	cout<<cnt;
	return 0;
}
