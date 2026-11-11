#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,s[500050],num,ma=0,v;
bool l=0;
int main(){
    cin>>n>>m;
    v=m;
    for(int i=0;i<n;i++)
    cin>>s[i];
    sort(s,s+n);
    for(int j=0;j<n-1;j++){
            m=v;
            num=1;
    for(int i=j;i<n-1;i++){
        if((s[i+1]-s[i])*(i+1-j)<=m)
        {
            num++;
            m-=(s[i+1]-s[i])*(i+1-j);
        }
        else
            break;
        if(i==n-2)
            l=1;
    }
    if(num>ma)
        ma=num;
    if(l==1)
        break;
    }
    cout<<ma;
    return 0;
}
