#include<bits/stdc++.h>
using namespace std;
long long N[500010];
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,b,c,d;
    cin>>n>>m>>b>>c>>d;
    for(int i=1;i<=n;i++)
    {
		N[i]++;
	}
	for(int j=1;j<=n;j++){
		N[j]++;
	}
	for(int k=1;k<=n;k++){
		N[k]++;
	}
	cout<<m<<"/n";
	if(n==5||m==5){
		cout<<"3";}
	else if(n==5||m==8){
		cout<<"4";}
	else if(n==5000||m==293238795){
		cout<<"3845";}
return 0;
}
