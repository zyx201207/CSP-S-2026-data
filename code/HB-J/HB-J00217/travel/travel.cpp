#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1 == c2){
        cout<<1;
        if(s1[0] == s2[0]&&s1[1] == s2[1]){
           cout<<1;
           int i1 = s1[0] - '0';
                int i2 = s2[0] - '0';
                i1 = i1 * 10;
                i2 = i2 * 10;
                i1 = i1 + (s1[1] - '0');
                i2 = i2 + (s2[1] - '0');
                if(i1 == i2){
                    cout<<1;
                    if((('A'<=s1[2]&&s1[2] <= 'C'&&'A'<=s2[2]&&s2[2] <= 'C')||('D'<=s1[2]&&s1[2] <= 'F'&&'D'<=s2[2]&&s2[2] <= 'F'))&&(abs(s1[2] - s2[2]) == 1)){
                        cout<<1;
                        return 0;
                    }
                    else{
                            cout<<0;
                            return 0;
                        }
                }
                else{
                cout<<"00";
                return 0;
                }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
