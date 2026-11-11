#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a;
    long long b;
    string c,s="";
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b;
        cin>>c;
        for(int j=1;j<=b;j++){
            s+=c;
        }
    }
    long long len=s.size()-1,p=0;
    int h=1;
    while(p<len){
        if(s[p]!=s[len]){
             h=0;
             break;
        }
        p++;
        len--;
    }
    string sum="",cnt="";
    if(h!=0)
        cout<<"0";
    else
    {
        long long g=0,u=0;
        for(long long i=0;i<s.size()/2;i++)
            sum[i]=s[i];
        for(long long i=s.size()-1;i<=s.size()/2;i++){
            cnt[u]=s[i];
            u++;
        }
        long long in=0;
        while(in<s.size()/2){
            if(sum[in]!=cnt[in])
                g++;
            in++;
        }
        cout<<g;
    }
}
