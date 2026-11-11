#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long l;
    cin>>l;
    string s;
    int a[100005];
    string c;
    int m=0;
    for(int i=0;i<l;i++){
        cin>>a[i]>>c[i];
        for(int d=0;d<a[i];d++)
            s+=c[i];
        m+=a[i];
    }
    int w=pow(10,m);
    string sum;
    for(int b=0;b<=m;b++){
        sum+=s[b];
    }
    int num=0;
    for(int e=0;e<m;e++)
        if(sum[e]==s[e])
            num++;
    if(num==m)cout<<0;
    return 0;
}

