//姓名：李承峰 学校：观山湖区外国语实验中学 准考证号：GZ-J00020
#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
string s;
int cc1,ss1,cc2,ss2;
char sa,sb;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<3;i++){
        if(i==0)
        {
            cc1+=(c1[i]-'0')*10;
            ss1+=(s1[i]-'0')*10;
            cc2+=(c2[i]-'0')*10;
            ss2+=(s2[i]-'0')*10;
        }if(i==1)
        {
            cc1+=(c1[i]-'0');
            ss1+=(s1[i]-'0');
            cc2+=(c2[i]-'0');
            ss2+=(s2[i]-'0');
        }if(i==2){
            sa=s1[2];
            sb=s2[2];
        }
    }
    if(cc1!=cc2){
        s="0000";
        cout<<s;
        return 0;
    }
    else{
        s+='1';
        if(ss1!=ss2){
            s+="000";
            cout<<s;
            return 0;
        }
        else{
            s+='1';
            if((sa<='C'&&sb<='C')||(sa>='D'&&sb>='D')){
                s+="1";
                if((sa=='B'&&(sb=='A'||sb=='C'))||(sb=='B'&&(sa=='A'||sa=='C'))||(sa=='D'&&sb=='F')||(sb=='D'&&sa=='F')){
                    s+='1';
                    cout<<s;
                    return 0;
                }
                else{
                    s+='0';
                }
            }
            else{
                s+="00";
                cout<<s;
                return 0;
            }
        }
    }
    cout<<s;
    return 0;
}
