#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<stack>
long long n,m,a[1000010],b[1000010],ans[1000010],j=1;
using namespace std;
int main()
 {
	  freopen("card.in","r",stdin);
	  freopen("card.out","w",stdout);
     stack<long long>s;
     cin>>n>>m;
     for(long long i=1;i<=n;i++)
      {long long x;
		 cin>>x;
		 b[i]=x;
	 }
     while(j<=n)
     {for(long long i=j;i<=n;i++)
		{
			if(a[b[i]]==1){
			while(s.top()!=b[i])
			  {a[s.top()]=0;s.pop();}
			}
			else
			  {s.push(b[i]);a[b[i]]=1;}
		}
	}
	j++;
	for(long long i=j;i<=m;i++)
	  if(a[i]==1)
	    ans[a[i]]++;
	for(long long i=1;i<=m;i++)
	   cout<<ans[i]<<" ";
    return 0;
 }
