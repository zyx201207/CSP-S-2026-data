#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    char c=s1[2],d=s2[2];
    string a=s1.erase(2,1),b=s2.erase(2,1);
    if(c1==c2){
        printf("1");
        if(a==b){
            printf("1");
            if(c=='A' && (d=='B' || d=='C') || c=='B' && (d=='A' || d=='C') || c=='C' && (d=='A' || d=='B')){
                printf("1");
                if(c+1==d || c-1==d) printf("1");
                else printf("0");
            }
            else if(c=='D' && d=='F' || c=='F' && d=='D'){
                printf("11");
            }
            else printf("00");
        }
        else printf("000");
    }
    else printf("0000");
    return 0;
}
