#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios_base::sync_with_stdio(false);
cin.tie(NULL);
long n;
cin>>n; 
long long a[n+1];
long long b=0;
long long ans=0;
char c[n+1];
string s;
for(int i=1;i<=n;i++){
	cin>>a[i]>>c[i];
}
for(int i=1;i<=n;i++){
	s+=a[i]*c[i];
	b+=a[i]/2;
}
cout<<0;
for(int i=0;i<=b;i++){
	    if(s[i]!=s[n-i]){
	    	ans++;
		}
}
ans+=1;
return 0;
}
