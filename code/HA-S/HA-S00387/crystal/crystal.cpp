#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=5e5+5;
ll a[N],c[N];
bool dog(int x,int y)
{
  return x<y;	
}
ll as(ll x,int d)
{
  ll n_1,n_2,n1_2;//i=x,d=mid	
  n_1=a[x]*(x-d+1);
  n_2=c[x]-c[x-d-1];
  n1_2=n_1-n_2;
  return n1_2;
}
int main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);	
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  ll m;
  cin>>n>>m;
  int i;
  a[0]=c[0]=0;
  bool b=0;
  for(i=1;i<=n;i++)
  {  
   cin>>a[i];
  }
  sort(a+1,a+n+1,dog);
  for(i=1;i<=n;i++)  
   c[i]+=c[i-1]+a[i];
  ll n1_2;	
  ll maxx=0;
  for(i=1;i<=n;i++)
  {
   int l=2,r=i,mid=(l+r)/2;
   while(l<=r)
   {
   	mid=(l+r)/2;
   	if(as(i,mid)>=m) l=mid+1;
   	else  r=mid-1;
   }
   if(maxx<i-r+1&&as(i,r)<=m)  maxx=i-r+1;//cout<<as(i,r)<<endl;}
  } 
  cout<<maxx<<'\n';
  
return 0;  	
}
