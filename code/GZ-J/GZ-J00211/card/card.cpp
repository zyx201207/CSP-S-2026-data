//姓名：朱芳贤，准考证号：GZ-J00211,学校：贵阳市第三中学
#include<bits/stdc++.h>
using namespace std;



int main(){
 freopen("card.in",'w',stdin);
 freopen("card.out","r",stdout);
 int n,m,a[i],sum,sdf;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
    cin>>a[i];
    if(n%2==1)
    {
        sum=n;
        sdf=n/2;
    }
    else
    {
      sum=n/2;
      sdf=n;
    }

 }
 cout<<sum<<sdf<<endl;


 return 0;


 }
