#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
bool ans[10]={0,0,0,0,0};

//wanzhengtongguosuoyouceshidian,100'
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    ans[1]=(c1==c2);
    ans[2]=(s1[0]==s2[0] and s1[1]==s2[1] and ans[1]);
    if('A'<=s1[2] and s1[2]<='C' and 'A'<=s2[2] and s2[2]<='C' and ans[1] and ans[2]){
        ans[3]=true;



    }
    if('D'<=s1[2] and s1[2]<='F' and 'D'<=s2[2] and s2[2]<='F' and ans[1] and ans[2]){
        ans[3]=true;

    }
    if(s1[2]=='B' or s2[2]=='B' or s1[2]=='D' or s1[2]=='F'){
        if(ans[3]){
            ans[4]=true;
        }

    }
    for(int i=1;i<=4;i++){
        if(ans[i]==true)cout<<"1";
        else cout<<"0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
