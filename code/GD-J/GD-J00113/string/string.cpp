#include<bits/stdc++.h>
using namespace std;int s;
int huiwen(string n)
{
	string c;int j=0,t=0;
	for(int i=s;i>0;i--)
	{
		c[j]=n[i];j++;
	}
	for(int i=0;i<s;i++)if(c[i]==n[i])t++;
	if(t==s)return 0;
	else return 1;
}
int main(){
	int n,m;char b;
	string a;
	cin>>m;
    for(int i=1;i<=m;i++){
    	cin>>n>>b;s+=n;
    	for(int j=s-n;j<s;j++){
    		a[j]=b; 

		}
	}freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);cout.tie(0);
    if(huiwen(a)){
    	string c;long long j=0,t=0;
		for(int i=s;i<0;i++)
		{
			c[j]=a[i];
		}
		for(int i=0;i<=s;i++)if(c[i]!=a[i])t++;
		cout<<t/2;
	}
	else cout<<0;
}
