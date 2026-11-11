#include<bits/stdc++.h>
using namespace std;
string c1;
string c2;
string s1;
string s2;
bool answer[4]={0,0,0,0};
int main()
{   freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        answer[0]=1;

        if(s1[0]==s2[0]){
            if(s1[1]==s2[1]){
                 answer[1]=1;
                 if((s1[2]=='A')&&(s2[2]=='B'||s2[2]=='C'))
                    answer[2]=1;
                else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))
                    answer[2]=1;
                else if((s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'))
                    answer[2]=1;
                else if((s1[2]=='F')&&(s2[2]=='D'))
                    answer[2]=1;
                else if((s1[2]=='D')&&(s2[2]=='F'))
                    answer[2]=1;


                if((s1[2]=='A')&&(s2[2]=='B'))
                    answer[3]=1;
                else if(s1[2]=='B'&&(s2[2]=='A'))
                    answer[3]=1;
                else if((s1[2]=='C')&&(s2[2]=='A'))
                    answer[3]=1;
                else if((s1[2]=='F')&&(s2[2]=='D'))
                    answer[3]=1;
                else if((s1[2]=='D')&&(s2[2]=='F'))
                    answer[3]=1;

                 }}}
    for(int i=0;i<4;i++){
        cout<<answer[i];
    }


    return 0;
}
