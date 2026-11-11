#include<bits/stdc++.h>
using namespace std;
long long a[130];
string s;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
for(long long i=1;i<=n;i++){
	long long x;
	char y;
	cin>>x>>y;
	a[y]+=x;
	while(x--){
		s+=y;
	}
}
long long i=0,j=s.size()-1,ans=0;
while(i<j){
	if(a[s[i]]>=a[s[j]]){
		if(s[j]!=s[i]){
		s[j]=s[i];
		ans++;	
		}
	}
	else if(a[s[i]]<a[s[j]]){
		if(s[i]!=s[j]){
		s[i]=s[j];
		ans++;	
		}
	}
	i++;
	j--;
}
cout<<ans;
	return 0;
}
