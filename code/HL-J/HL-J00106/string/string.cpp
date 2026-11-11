#include<bits/stdc++.h>
using namespace std;
 int anum[200005];char alett[200005];
 int numb;
 long long alln;
 int main()
{
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
  cin>>numb;
  for(int i=1;i<=numb;i++)
  {
    cin>>anum[i];
    cin>>alett[i];
    alln+=anum[i];

  }

long long leiji=0,leiji2=0 ,leiji3=numb+1,leiji4=alln+1,cnt=0, i2;
  for(long long i=1;i<=alln/2;i++)
  {i2=alln-i+1;
  if(i2<leiji4){leiji3-=1;leiji4-=anum[leiji3];}
      if(i>leiji2){leiji+=1;leiji2+=anum[leiji];}
    if(!(alett[leiji]==alett[leiji3]))
    {
        cnt++;
    }


}cout<<cnt;return 0;}
