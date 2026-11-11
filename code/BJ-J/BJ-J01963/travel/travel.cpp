#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a,b,c;
a="";
void panduan(string q,w,e,t){
    if(q==e) a+="1";
    else{
        a+="0000";
        int f=int(a)
        return f;
        break;
    }
    if(w[0]==t[0] and w[1]==t[1]) a+="1";
    else{
        a+="000";
        int f=int(a)
        return f;
        break;
    }
    if(((w[2]=="A" or "B" or "C") and (t[2]=="A" or "B" or "C")) or ((w[2]=="D" or "F") and (t[2]=="D" or "F"))){
        a+="1";
    }
    else{
        a+="00";
        int f=int(a)
        return f;
        break;
    }
    if(w[2]=="A" or "B" or "C"){
        if(w[2]=="A"){
            if(t[2]=="B"){
                a+="1";
            }
            else{
                a+="0";
                int f=int(a)
                return f;
                break;
            }
        }
        if(w[2]=="B"){
            if(t[2]=="A" or "C"){
                a+="1";
            }
            else{
                a+="0";
                int f=int(a)
                return f;
                break;
            }
        }
        if(w[2]=="C"){
            if(t[2]=="B"){
                a+="1";
            }
            else{
                a+="0";
                int f=int(a)
                return f;
                break;
            }
        }
    }
    else{
        if(w[2]=="D"){
            if(t[2]=="F"){
                a+="1";
            }
            else{
                a+="0";
                int f=int(a)
                return f;
                break;
            }
        }
        if(w[2]=="F"){
            if(t[2]=="D"){
                a+="1";
            }
            else{
                a+="0";
                int f=int(a)
                return f;
                break;
            }
        }
    }
    int f=int(a)
    return f;
}
int main(){
    cin>>c1>>s1>>c2>>s2;
    int ans=panduan(c1,s1,c2,s2);
    cout<<ans;
}
