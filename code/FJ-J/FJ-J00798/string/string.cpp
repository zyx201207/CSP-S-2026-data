#include<bits/stdc++.h>
long long a[2000001],s[20000000];
char c[20000001];
int b[200000001];
	
using namespace std;
int h(int v){


	int i=0;
	while(v>0)
	{
		i++;
		v=v-a[i];
		
	}

	return i;
	
}
int main(){
	
	
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
   int n,i,d,m=0,l=0;
   
 
  
 cin>>n;
 
for(i=1;i<=n;i++)
{
	cin>>a[i]>>c[i];
	l+=a[i];
}
for(i=1;i<=1;i++)
{
	if(i>s[j])
	{
		j++;
		b[i]=j;
		
	}
}
	for(i=1;i<=1/2;i++)
	{
		if(c[b[i]]!=c[b[l-i+1]])
	{
		
		m++;
	}
		
	}
	cout<<m;
	return 0;
	
		
		
}
