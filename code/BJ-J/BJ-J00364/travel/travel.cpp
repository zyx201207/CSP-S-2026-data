#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cr,sr,cx,sx;
    cin>>cr>>sr>>cx>>sx;

    int numr=0,numx=0;
    char letr,letx;
    for(int i=0;i<3;i++){
        int temp=0;
        if(sr[i]>='0' && sr[i]<='9'){
            if(temp==0){
                numr+=sr[i]*10;
            }else{
                numr+=sr[i];
            }
        }else{
            letr=sr[i];
        }
        if(sx[i]>='0' && sx[i]<='9'){
            if(temp==0){
                numx+=sx[i]*10;
            }else{
                numx+=sx[i];
            }
        }else{
            letx=sx[i];
        }
    }

    if(cr!=cx){ //判定
        cout<<"0000";
        return 0;
    }
    if(cr==cx && numr!=numx){
        cout<<"1000";
    }
    if(cr==cx && numr==numx){
        if(letr=='A' || letr=='B' || letr=='C'){
            if(letx=='D' || letx=='F'){
                cout<<"1100";
                return 0;
            }
            if(letx=='A' || letx=='B' || letx=='C'){
                cout<<"111";
                if(letx=='B' ||  letr=='B'){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
                return 0;
            }
        }
        if(letx=='A' || letx=='B' || letx=='C'){
            if(letr=='D' || letr=='F'){
                cout<<"1100";
                return 0;
            }
            if(letr=='A' || letr=='B' || letr=='C'){
                cout<<"111";
                if(letx=='B' ||  letr=='B'){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
                return 0;
            }
        }
        if(letr=='D' || letr=='F'){
            if(letr=='A' || letr=='B' || letr=='C'){
                cout<<"1100";
                return 0;
            }
            if(letr=='D' || letr=='F'){
                cout<<"1111";
                return 0;
            }
        }
        if(letx=='D' || letx=='F'){
            if(letr=='A' || letr=='B' || letr=='C'){
                cout<<"1100";
                return 0;
            }
            if(letr=='D' || letr=='F'){
                cout<<"1111";
                return 0;
            }
        }
    }
    return 0;
}
