#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200000000];
char b[105];
string x,y;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        x+=b[i];
}
for(int i=n;i>=0;i--){
    y+=x[i];
}
int cnt=0;
//cout<<x<<endl<<y<<endl;
for(int i=0;i<n;i++){
   // cout<<x[i]<<" "<<y[i]<<" "<<(x[i]==y[i])<<endl;
        if(x[i]!=y[i+1]){
          cnt+=a[i+1];
        }


}
if((cnt/2.0)!=(cnt/2))
cout<<cnt/2+1;
else
    cout<<cnt/2;
return 0;
}
