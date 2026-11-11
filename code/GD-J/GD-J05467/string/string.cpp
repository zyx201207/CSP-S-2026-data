#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin>>a;
    long long b[200000]={0};
    char c[200000]={'0'};
    for(int i=0;i<a;i++)
    {
        cin>>b[i];
        cin>>c[i];
    }
    long long b1[200000];
    char c1[200000]={0};
    for(int i=0;i<a;i++)
    {
        b1[a-i-1]=b[i];
        c1[a-i-1]=c[i];
    }
    long long x[200000]={0};
    for (int i=0;i<a;i++)
    {
        x[i]=i;
    }
    long long x1[200000]={0};
    for (int i=0;i<a;i++)
    {
        x1[a-i-1]=i;
    }
    long long n=0;
    long long q=0,w=0;
    while(x[q]!=x1[w]){

        if(b[q]==0) q++;
        if(b1[w]==0)w++;
        long long z=min(b[q],b1[w]);
        if(c1[q]!=c[w])
        {
            b[q]-=z;
            b1[w]-=z;
            n+=z;
        }
        else{
            b[q]-=z;
            b1[w]-=z;
        }

    }

    cout<<n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
