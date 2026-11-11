//姓名：朱芳贤，准考证号：GZ-J00211,学校：贵阳市第三中学
#include<bits/stdc++.h>
using namespace std;



int main(){
 freopen("string.in",'w',stdin);
 freopen("string.out","r",stdout);
 int n,sum=0;
 cin>>n;
 int a[i],b[i];
 for(int i=1;i<=n;i++)
 {
   cin>>a[i]>>b[i];
   for(int j=1;j<=n;j++)
   {
     if(b[i]=b[i-1])
     {
       cout<<0;
     }
     else
     {
       for(int m=1;m<=n;m++)
       {
          sum=a[i]+a[i+1];
          cout<<sum-n<<endl;
       }
     }
   }

 }
 return 0;
}
