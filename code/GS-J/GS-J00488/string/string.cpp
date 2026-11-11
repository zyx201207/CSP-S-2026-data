#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,js=0;
char a;
double l=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&m);
    	cin>>a;
    	l+=m; 
    	for(int j=1;j<=m;j++)
    	   	s+=a; 
	}
	l--;
	for(int i=1;i<=l/2;i++)
	    for(int j=l;j>=l/2;l++)
	        if(s[i]!=s[j])
	        js++;
	printf("%d",js);
	return 0;
} 
