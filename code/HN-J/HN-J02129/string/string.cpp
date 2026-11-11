#include<bits/stdc++.h>
using namespace std;
//string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,ans=0,b=0,d=0;
	char a,s[204000];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>a;
		for(int j=1;j<=m;j++)
		{
			s[b]=a;
			b++;
			
		}
	}
	if(b%2==0){
		for(int i=0;i<(b/2+1);i++)
	    {
		if(s[d]!=s[b-d])ans++;
	    }
	}else{
		for(int i=0;i<(b/2);i++)
	    {
	    	if(s[d]!=s[b-d])ans++;
		    
	    }
	}
	
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
