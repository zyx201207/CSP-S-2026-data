#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,k=1;
    long long m;
    int x;
    long long y=0,z=0;
    cin>>n>>m;
    int c=0;
    int a[500005],b[500005];
    if(m<1000){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            y=0;
            x=a[i];
            for(int j=0;j<=i;j++){
                y+=x-a[j];
                z+=1;

            }
            if(y<=m){
                b[c]=z;
                c++;
            }
            z=0;
        }
        sort(b,b+c);
        cout<<b[c];
        return 0;

    }
    return 0;
}
