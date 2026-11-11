#include<bits/stdc++.h>
using namespace std; 
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);	
string s;
int n;
cin>>n;
long long a[n];
char b[n];
for(int i=1;i<=n;i++){
cin>>a[i]>>b[i];
for(int j=1;j<=a[i];j++){
	s+=b[i];	
}
}
string s1=s;
int x=s.size(),sum=0;
for(int i=1;i<=x/2;i++){ 
	if(s[i]!=s1[x]&&s1[x]>='a'&&s1[x]<='z'){
		sum++;
	}
	x--;
}
	cout<<sum;
	return 0;
} 
