#include<bits/stdc++.h>
using namespace std;
int n,c,b[15];
string a;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin.tie(0);
cout.tie(0);
cin>>n;
for(int i=1;i<=n;i++){
	char c;
	cin>>b[i]>>c;
	for(int j=1;j<=b[i];j++){
	a+=c;
	}
}
int j=a.length();
for(int i=0;i<a.length();i++){
	if(i<=j){
	break;
	}
	if(a[i]!=a[j]){
	c++;
	}
}
if(a.length()%2!=0){
c--;
}
cout<<c;
	return 0;
}
