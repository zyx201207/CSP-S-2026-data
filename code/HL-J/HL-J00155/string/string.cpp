#include<bits/stdc++.h>
using namespace std;
int main (){
string c;
long long n,a,sum=0;
cin>>n;
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
for(int i=1;i<=n;i++){
	cin>>a>>c;
	if(a%2==0) sum+=1;
	else sum+=a;
	if(c==c)
	cout<<"0";
}
cout<<sum;
return 0;
}

