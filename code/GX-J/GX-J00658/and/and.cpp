#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long R[200005];
long long X;
long long Max_=0;

int main()
{   freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>R[i];}

    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if (i==j)continue;
        if(R[i]&R[j]>Max_)
            Max_=R[i]&R[j];
}}
    cout<<Max_;





    return 0;
}
