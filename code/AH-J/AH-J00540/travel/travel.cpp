#include<bits/stdc++.h>
using namespace std;
int main(void){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1.substr(0,2)==s2.substr(0,2)){
            cout<<1;
            if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D')){
                cout<<1;
                if(abs(s1[2]-s2[2])==1){
                    cout<<1;
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
//Hello
//I'm a nine-grader and that means this is my last chance to join in the CSP.
//I don't know if somebody could read these lines.I hope I can attend the mi2huo4xing2wei2da4shang3.
//Have a good time.
//Code by __LCD(Luogu uid:1057768)

//I'm not good at English.So you can see it as a joke.

//37 minutes:address T1 & T2 (Emm,maybe I can get 200+ scores?)
//59 minutes:T3,difficult.(I'm cai4)
//92~101 minutes:T3 bully,expect 45pts.(well,It seems that something went wrong in the clock.So i don't know what time is it from now.)
//102 minutes:The clock is fixed.
//103 minutes:I'd like to take a break.I'll sleep...But the table is so hard that I can't fall sleep easily.uh,maybe I can have a break when it ends.
//131 minutes:T4 bully,except 36pts.
//195 minutes:My deskmate(?) is noisy,but i don't want to do anything because i'm tired.
//200 minutes:Check check my program.Checkmate!(a term in chess.That means a king be checked and can't react)

//except:
//T1:0~100    points
//T2:0~100    points
//T3:0~50     points
//T4:0~36     points
//Total:0~286 points

//if i don't got these points,cai3 bao4 wo3 pls.

//vegetable dog.(bei1
