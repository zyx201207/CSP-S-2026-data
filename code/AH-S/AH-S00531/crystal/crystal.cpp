#include<iostream>
using namespace std;
int a[100];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m;
cin>>n>>m;
for(int j=1;j<=n;j++)

{
 cin>>a[j];
}
int cnt=a[n/2+1];
cout<<cnt;
    for(int j=1;j<=n;j++)
    {
        if(a[j]<cnt){
            int c=cnt-a[j];
            a[j]+=c;
            m-=c;
        }

    }



int ans=0;
for(int j=1;j<=n;j++)
{

    if(a[j]==cnt)ans++;
}
cout<<ans;


return 0;
}
