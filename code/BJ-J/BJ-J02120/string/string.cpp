#include<bits/stdc++.h>
using namespace std;
long long cnt=0,num;
pair<long long ,char>p[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    char c;
    long long n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>c;
        cnt+=m;
        for(int j=1;j<=m;j++)s+=c;
    }
    string a=s;
    reverse(s.begin(),s.end());
    for(int i=1;i<=cnt/2;i++){
        if(s[i]!=a[i])num++;
    }
    if(num)cout<<num+1;
    else cout<<0;
    //cout<<a<<endl<<s;
}