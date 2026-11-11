#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("crystal.in","in",stdin);
freopen("crystal.out","out",stdout);
int n,m,c,s,a;
cin>>n>>m>>c>>s;
a=c+s;
if(a<1){
	cout<<(c+s)*-1;
	return 0;
}
cout<<a;
fclose(stdin);
fclose(stdout);
return 0;
}
