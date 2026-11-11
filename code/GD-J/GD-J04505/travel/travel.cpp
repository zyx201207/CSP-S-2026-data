#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
  long long a,b;
  string s1,s2;
  long long sum=0;
  cin>>a>>s1>>b>>s2;
  if(a==b)
  {
  	sum++;
  	cout<<1;
  }
  else cout<<0;
 long long c=s1[0]*10+s1[1];
 long long d=s2[0]*10+s2[1];
 if(sum==1&&c==d)
 {
 	sum++;
 	cout<<1;
 }
 else cout<<0;
 long long e=s1[2]-'0';
 long long f=s2[2]-'0';
// cout<<endl<<s1[2]<<" "<<s2[2]<<endl;
// cout<<endl<<e<<" "<<f<<endl;
 if(sum==2&&((e-19<=0&&f-19<=0)||(e-19>0&&f-19>0)))
 {
 	sum++;
 	cout<<1;
 }
 else cout<<0;
 if(sum==3&&(e==f+1||e==f-1))
 {
 	cout<<1;
 	
 }
 else cout<<0;
 return 0;
}
