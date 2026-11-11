#include<bits/stdc++.h>
using namespace std;
string ck(string a,string b){

    if(a==b){
        return "111";
    }
    if(a[0]==b[0]&&a[1]==b[1]){

        if(a[2]<='C'&&b[2]<='C'||a[2]>='D'&&b[2]>='D'){

            if(abs(a[2]-b[2])==1){
                return "111";
            }
            else{
                return "110";
            }
        }
        else{
            return "100";
        }
    }
    else{
        return "000";
    }


}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int r,x;
    string rs,xs;
    cin>>r>>rs>>x>>xs;
    if(r==x){
        cout<<"1";
        cout<<ck(rs,xs);
    }
    else{
        cout<<"0000";
    }
    return 0;
}
