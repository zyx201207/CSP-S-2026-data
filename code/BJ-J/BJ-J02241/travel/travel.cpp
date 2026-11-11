#include<bits/stdc++.h>
using namespace std;
char c1[4],s1[4],c2[4],s2[4];
bool tcx=1,tp=0,tce=0,xl=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<2;i++){
        if(c1[i]!=c2[i]){
            tcx=0;
            break;
        }
    }
    if(tcx){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            tp=1;
        }
        if(tp){
            if(s1[2]<=67&&s2[2]<=67) tce=1;
            else if(s1[2]>67&&s2[2]>67) tce=1;
            if(tce){
                if(abs(s1[2]-s2[2])==1) xl=1;
            }
        }
    }
    cout<<tcx<<tp<<tce<<xl;
    return 0;
}
