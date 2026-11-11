#include <iostream>
using namespace std;
int p[5];
string s1,s2,s3,s4;
char c1,c2;
bool ch(char c3,char c4){ return (c1==c3)&&(c2==c4); }
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    c1=s2[2],c2=s4[2];
    if(s1==s3){
        p[1]=1;
        if(s2[0]==s4[0]&&s2[1]==s4[1]){
            p[2]=1;
            if((c1<='C')==(c2<='C')){
                p[3]=1;
                if(ch('A','B')||ch('B','A')||ch('B','C')||ch('C','B')||ch('D','F')||ch('F','D')) p[4]=1;
            }
        }
    }
    for(int i=1;i<=4;i++) cout<<p[i];
    return 0;
}
