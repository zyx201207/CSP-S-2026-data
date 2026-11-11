 #include<bits/stdc++.h>
using  namespace  std;
int const  N=1e5+10;
int  a[N],b[N];
int main()
{
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
  int n,m,sum=0;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
   {
    cin>>a[i];
  	sum=max(sum,a[i]&a[i+n-1]);
   }
  cout<<sum;
	return 0;
}
