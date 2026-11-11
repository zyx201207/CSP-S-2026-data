//GZ-J00554 韦腾宇 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
string q; 
long long n,a[200020],m,g,sj=0,zl[200010],andd;
char b[10000],su[10000];
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
    cin>>n;
    for(long long i=0;i<n;i++)
    {
    	cin>>a[i]>>b[i];
    m=m+a[i];
    	
	}
	for(long long i=0;i<n;i++)
    {
     for(long long ll=0;ll<a[i];ll++)
    {
    	
    	su[sj++]=b[i];
    	
	}
    	
	}
   for(long long i=0;i<strlen(su)/2;i++)
    {
    
    if(su[i]!=su[m-i-1]&&i!=m) 
    {
    	andd++;
	}
	}
	cout<<andd;
	return 0;
} 
