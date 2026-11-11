#include<bits/stdc++.h>
using namespace std;
long long n,m[250000],zs=0,ks=0,l=0,sum=0;
string q[250000],s[250000];
bool b=true;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin >> n;
for(int i=1;i<=n;i++){
	cin >> m[i] >> q[i];
	if(i==2 and q[i]!=q[i-1]) b=false;
	zs+=m[i];
}
if(b==true){
	cout<<"0";
	return 0;
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=m[i];j++){
		s[j]=q[i];
	}
}

if(zs%2==1){
	ks=zs/2+1;
for(int i=ks;i<=zs;i++){
	if(s[i]!=s[i-l]){
		sum++;
	}
	l+=2;
}
}
else{
		ks=zs/2+1;
		l=1;
for(int i=ks;i<=zs;i++){
	if(s[i]!=s[i-l]){
		sum++;
	}
	l+=2;
}
}
cout<<sum;
}
