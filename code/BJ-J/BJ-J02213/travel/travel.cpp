#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int ans=0;
    int anss=0;
    int ansss=0;
    int anssss=0;
    char r[3];
    char x[3];
    char rr[4];
    char xx[4];
    for(int i=1;i<=2;i++){
        cin>>r[i];
    }
    for(int i=1;i<=3;i++){
        cin>>rr[i];
    }
    for(int i=1;i<=2;i++){
        cin>>x[i];
    }
    for(int i=1;i<=3;i++){
        cin>>xx[i];
    }
    if(r[1]==x[1] && r[2]==x[2]){
        ans=1;
        if(rr[1]==xx[1] && rr[2]==xx[2]){
            anss=1;
            if((rr[3]=='A') || (rr[3]=='B') || (rr[3]=='C') && (xx[3]=='A') || (xx[3]=='B') || (xx[3]=='C')){
                ansss=1;
                if((rr[3]=='A') && (xx[3]=='B')){
                    anssss=1;
                }
                if((rr[3]=='B') && (xx[3]=='C')){
                    anssss=1;
                }
                if((rr[3]=='C') && (xx[3]=='D')){
                    anssss=1;
                }
                if((rr[3]=='D') && (xx[3]=='f')){
                    anssss=1;
                }
                if((rr[3]=='F') && (xx[3]=='D')){
                    anssss=1;
                }
                if((rr[3]=='D') && (xx[3]=='C')){
                    anssss=1;
                }
                if((rr[3]=='C') && (xx[3]=='B')){
                    anssss=1;
                }
                if((rr[3]=='B') && (xx[3]=='A')){
                    anssss=1;
                }
            }
            else if((rr[3]=='D') || (rr[3]=='E') && (xx[3]=='D') || (xx[3]=='E')){
                ansss=1;
                if((rr[3]=='A') && (xx[3]=='B')){
                    anssss=1;
                }
                if((rr[3]=='B') && (xx[3]=='C')){
                    anssss=1;
                }
                if((rr[3]=='C') && (xx[3]=='D')){
                    anssss=1;
                }
                if((rr[3]=='D') && (xx[3]=='f')){
                    anssss=1;
                }
                if((rr[3]=='F') && (xx[3]=='D')){
                    anssss=1;
                }
                if((rr[3]=='D') && (xx[3]=='C')){
                    anssss=1;
                }
                if((rr[3]=='C') && (xx[3]=='B')){
                    anssss=1;
                }
                if((rr[3]=='B') && (xx[3]=='A')){
                    anssss=1;
                }
            }
        }
    }
    cout<<ans<<anss<<ansss<<anssss;
    return 0;
}
