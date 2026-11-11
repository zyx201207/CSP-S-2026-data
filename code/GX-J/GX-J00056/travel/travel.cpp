#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    string a="0000";
    if(c1==c2){
        a[0]='1';
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            a[1]='1';
            if((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')){
                a[2]='1';
                if(((s1[2]=='A' || s1[2]=='B') && (s2[2]=='A' || s2[2]=='B')) || ((s1[2]=='B' || s1[2]=='C') && (s2[2]=='B' || s2[2]=='c'))){
                    a[3]='1';
                }
            }
            else if((s1[2]=='D' || s1[2]=='E' ) && (s2[2]=='D' || s2[2]=='E' )){
                a[2]='1';
                a[3]='1';
            }
        }
    }
    cout<<a;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
