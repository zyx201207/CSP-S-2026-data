#include<bits/stdc++.h>
using namespace std;
long long n,d,l,bh;
char zm;
string a,b;
int main(){
freopen("string.in","r",stdin);	
freopen("string.out","w",stdout);	
cin>>n;
for(int i=1;i<=n;i++){
cin>>d>>zm;
for(int i=0;i<d;i++){
	a=a+zm;
	b=zm+b;
}	
}
l=a.size();
for(int i=0;i<(l+1)/2;i++){
    if(a[i]!=b[i])bh++;
}
cout<<bh;
fclose(stdin);
fclose(stdout);
return 0;
}

