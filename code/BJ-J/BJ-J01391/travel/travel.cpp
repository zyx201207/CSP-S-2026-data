#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int a = 0,b = 0;
    int l1 = s1.size();
    for(int i = 0;i < l1;i++){
        a = a * 10 + s1[i] - 48;
        b = b * 10 + s3[i] - 48;
    }
    if(a == b){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    int l2 = s2.size();
    int c = 0,d = 0,e = s2[l2 - 1],f = s4[l2 - 1];
    for(int i = 0;i < l2 - 1;i++){
        c = c * 10 + s2[i] - 48;
        d = d * 10 + s4[i] - 48;
    }
    if(c == d){
        if(e <= 'C'&&f <= 'C'||e >= 'D'&&f >= 'D'){
            cout<<11;
        }else{
            cout<<100;
            return 0;
        }
        if(abs(s2[l2 - 1] - s4[l2 - 1]) == 1){
            if((s2[l2 - 1] == 'D'||s2[l2 - 1] == 'C')&&s4[l2 - 1] == 'D'||s4[l2 - 1] == 'C'){
                cout<<0;
            }else{
                cout<<1;
            }
        }else{
            cout<<0;
        }
    }else{
        cout<<"000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
