# include <bits/stdc++.h>
using namespace std;
char c1[2],c2[2],s1[3],s2[3];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<=1;i++)cin>>c1[i];
    for(int i=0;i<=2;i++)cin>>s1[i];
    for(int i=0;i<=1;i++)cin>>c2[i];
    for(int i=0;i<=2;i++)cin>>s2[i];
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            char b1,b2;
            b1=s1[2];
            b2=s2[2];
            if((b1>='D'&&b2>='D')){
                cout<<"1111";
                return 0;
            }else if(b1<='C'&&b2<='C'){
                if(b1-1==b2||b2-1==b1){
                    cout<<"1111";
                    return 0;
                }else{
                    cout<<"1110";
                    return 0;
                }
            }else{
                cout<<"1100";
                return 0;
            }
        }else{
            cout<<"1000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
