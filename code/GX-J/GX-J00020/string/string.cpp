#include<iostream>
using namespace std;
int n,a[200005];
long long ssum,sum;
char c[200005];
string x;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++)x[sum+j]=c[i];
        sum+=a[i];
    }
    for(int i=0;i<sum/2;i++){
        if(x[i]!=x[sum-1-i])ssum++;
    }
    cout<<ssum;
    return 0;
}
