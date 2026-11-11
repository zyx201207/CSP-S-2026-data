#include<bits/stdc++.h>
using namespace std;
long long n,a[100];
string b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i]>>b[i];
	}
    if(n==1)  cout<<"0";
    if(n==2)
    {
		if(b[1]-'a'==b[2]-'a') cout<<"0";
		else cout<<min(a[1],a[2]);
	}
return 0;
}
