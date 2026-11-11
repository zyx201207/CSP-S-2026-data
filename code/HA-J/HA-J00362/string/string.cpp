#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100000000000];
	char b[1000000000000],s,s2;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++) 
{
	while(n==2){
	b[i]=b[n];
	cout<<0;	
	}
	while(n==3){
		b[1]!=b[n];
		if(a[1]>a[n])
		cout<<a[1];
		else cout<<a[n]; 
	}
	if(((b[i+1]==b[n-i])&&(b[1]==b[n]))&&((a[i+1]==a[n-i])&&(a[1]==a[n])))cout<<0;
	while(n>3){
		if(b[1]!=b[n]&&(a[i]==a[i+1]))
		cout<<(n/2)*a[i];
	}	
	}
}
fclose(stdin);fclose(stdout);
}
