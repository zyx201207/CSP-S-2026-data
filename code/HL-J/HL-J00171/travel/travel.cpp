#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int ans1,ans2,ans3,ans4;
char n[6] = {'A','B','C','D','F'};
bool judge1(){
    return c1 == c2;
}bool judge2(){
    if(judge1()){
        return s1[0] == s2[0] && s1[1] == s2[1];
    }return false;
}bool judge3(){
    if(judge2()){
        if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
            if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
                return true;
            }return false;
        }else{
            if(s2[2] == 'D' || s2[2] == 'F'){
                return true;
            }return false;
        }
    }return false;
}bool judge4(){
    if(judge3()){
        for(int i = 0;i < 5;i++){
            if(s1[2] == n[i]){
                if((i-1 >= 0 && s2[2] == n[i-1]) || (i+1 < 5 && s2[2] == n[i+1])){
                    return true;
                }return false;
            }
        }
    }return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    ans1 = judge1();
    ans2 = judge2();
    ans3 = judge3();
    ans4 = judge4();
    cout << ans1 << ans2 << ans3 << ans4 << '\n';
    return 0;
}
