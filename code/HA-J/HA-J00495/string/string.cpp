#include<bits/stdc++.h>
using namespace std;
struct a{
	int b;
	char c;
};
int n,cnt=0,y=0;
bool k=false;
string e,f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a d[n];
	for(int i=1;i<=n;i++)
	{
		cin>>d[i].b>>d[i].c;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i].c!=d[i-1].c){
			k=true;
		}
	}
	if(!k){
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=d[i].b;j++){
			e=e+d[i].c;
		}
	}
	if(e.size()%2==0){
			int j=0;
	for(int i=1;i<=e.size()/2;i++)
	{
		f=f+e[i];
	}
	for(int i=e.size();i>e.size()/2;i--)
	{
	    if(e[i]!=f[j]){
	    	cnt++;
	    }
	    j++;
	}}
	else if(e.size()%2!=0){
	int j=0;
	for(int i=1;i<=e.size()/2;i++)
	{
		f=f+e[i];
	}
	for(int i=e.size();i>e.size()/2+1;i--)
	{
	    if(e[i]!=f[j]){
	    	cnt++;
	    }
	    j++;
	}}
	cout<<cnt;}
	else{
		cout<<0;
	}
	return 0;
}
