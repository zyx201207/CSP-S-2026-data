#include<bits/stdc++.h>
using namespace std;
struct str{
    int a;
    char c;
}s[200005];
string s1,s2,s3;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d %c",&s[i].a,&s[i].c);
        for(int j=1;j<=s[i].a;j++){
            s1=s1+s[i].c;
        }
    }

    s2=s1;
    reverse(s2.begin(),s2.end());
    for(int i=0;i*2<s2.size();i++){
        if(s1[i]!=s2[i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
