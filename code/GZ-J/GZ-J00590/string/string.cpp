//GZ-J00590 北京师范大学贵阳附属中学 张朋
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        for(int j=0;j<a;j++)
            s+=b;
    }
    string s1;
    for(int i=n+1;i>=0;i--)
        s1+=s[i];
    if(s1==s)
        cout<<'0';
    int num=0;
    for(int i=0;i<n;i++)
        if(s[i]!=s1[i])
            num++;
    cout<<num;
return 0;
}
