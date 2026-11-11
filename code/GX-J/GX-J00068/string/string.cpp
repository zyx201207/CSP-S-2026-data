#include <bits/stdc++.h>
using namespace std;

long long n,v=0;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    long long  a[200005];
    char b[200005];
    char m[200005];
    long long c=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        v=v+a[i];

    }

    for(int i=0;i<n;i++){
        for(int j=1;j<=a[i];j++){
                m[j]=b[i];
                //cout<<m[j];

    }

    }


    for(int L=0;L<=v/2;L++){


        if(m[L]!=m[v-L])
        {

            c+=1;


        }
        else{
            c+=0;
        }


    }
    cout<<0;
    return 0;}

