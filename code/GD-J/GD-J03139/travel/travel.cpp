#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string ans = "0000";
    string l = "ABC";
    string r = "DE";
    if(c1 == c2){
        ans = "1000";
        if(s1[1] != s2[1]){
            ans = "1100";
        }
        else{
            for(int i = 0;i<3;i++){
                if(s1[2] != l[i] && s2[2] != l[i]){
                    ans = "1111";
                }
            }
            for(int i = 0;i<2;i++){
                if(s1[2] != r[i] && s2[2] != r[i]){
                    ans = "1110";
                }
            }
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
