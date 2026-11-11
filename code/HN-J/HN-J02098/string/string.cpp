#include<bits/stdc++.h>
using namespace std;
long long i,n,k,m=1,a[1000000];
string s;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);	

cin>>n;
for(i=0;i<n;i++){
cin>>a[i];
cin>>s[i];

}
for(i=0;i<n;i++){
if(s[i]==s[n-1]){
m=0;
break;
}

}
	for(i=1;i<n;i++){
		if(s[0]!=s[i]){
			k=k+a[i];
		}
	}
if(m==0){
	cout<<m;
}else{
	cout<<k;
}
	

	

return 0;
}

	

