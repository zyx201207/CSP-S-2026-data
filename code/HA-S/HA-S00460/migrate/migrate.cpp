 #include <bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
int c,t;
cin>>c>>t;
int n,m;
for(int j=0;j<t;j++)
{
cin>>n>>m;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
int steps[5005],l=0,f=0;
int sum=0;
for(int i=0;i<n;i++)
{
for(int h=n-1;h>=0;h--)
{
  for(int k=1;k<=m;k++)
  
{
  
if((h-i)%k==0)
  {
  
steps[f++]=(h-i)/m;
  }
  else
  {
  
steps[f++]=(h-i)/m+1;
  }
  for(int j=0;j<f;j++)
  {
  
for(int g=j+1;g<f;g++)
  
{
  
if(steps[j]==steps[g])
  
{
  
l++;
  
}
  
}
}
  
}
  
if(l==2)
  
{
  
sum++;
  
}
  }
}
cout<<sum<<endl;
}
   return 0;
}
 
                        
