#include <bits/stdc++.h>
using namespace std;
string s,qbd,hbd;
int cnt1,cnt2,m;
int main()
{
    freopen("string.in","/home/noilinux/string",stdin);
    freopen("string.out","/home/noilinux/string",stdout);
    cin>>m;
    int cd2=1;
    for(int i=1;i<=m;i++){
        int a;
        char b;
        cin>>a>>b;
        for(int j=cd2;j<=cd2+a;j++){
            s[j]=b;
        }
        cd2+=a;
    }
    int sd=s.length();
    int ybcd=sd/2;
    for(int i=1;i<=ybcd;i++){
        qbd[i]=s[i];
    }
    for(int i=ybcd+1;i<=sd;i++){
        hbd[i]=s[i];
    }
    for(int i=1;i<=ybcd;i++){
        for(int j=sd;j>=ybcd+1;j--){
            if(qbd[i]!=hbd[j])  cnt1++;
        }
    }
    for(int i=ybcd+1;i<=sd;i++){
        for(int j=ybcd;j>=1;j--){
            if(hbd[i]!=qbd[j])  cnt2++;
        }
    }
    cout<<cnt1<<cnt2;
    return 0;
}
