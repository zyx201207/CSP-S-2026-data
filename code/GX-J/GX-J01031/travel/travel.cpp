#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2,ans;
    getline(cin,c1);
    getline(cin,s1);
    getline(cin,c2);
    getline(cin,s2);
    if(c1[0]-'0'==c2[0]-'0'&&c1[1]-'0'==c2[1]-'0'){
        ans[0]='1';
    }
    else{
        ans[0]='0';
    }
    if(ans[0]=='1'){
        int x;
        if(s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0'){
            x=1;
        }
        else{
            x=0;
        }

        if(x){
            ans[1]='1';
        }
        else{
            ans[1]='0';
        }
        if(x){
            if(abs(s1[2]-s2[2])==1||abs(s1[2]-s2[2])==2){
                if(s1[2]=='C'&&s2[2]=='D'){
                    ans[2]='0';
                }
                else if(s1[2]=='D'&&s2[2]=='C'){
                    ans[2]='0';
                }
                else{
                    ans[2]='1';
                }
                if(ans[2]=='1'){
                    if(s1[2]=='D'&&s2[2]=='F'){
                        ans[3]='1';
                    }
                    else if(s1[2]=='F'&&s2[2]=='D'){
                        ans[3]='1';
                    }
                    else if(s1[2]=='A'&&s2[2]=='C'){
                        ans[3]='0';
                    }
                    else if(s1[2]=='C'&&s2[2]=='A'){
                        ans[3]='0';
                    }
                    else{
                        ans[3]='1';
                    }
                }
                else{
                    ans[3]='0';
                }
            }
            else{
                ans[2]='0';
                ans[3]='0';
            }
        }
        else{
            ans[2]='0';
            ans[3]='0';
        }



        }
    else if(ans[0]=='0'){
        ans[1]='0';
        ans[2]='0';
        ans[3]='0';
    }
    for(int i=0;i<4;i++){
        cout<<ans[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
