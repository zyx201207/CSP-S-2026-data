#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool ans1,ans2,ans3,ans4;
    char ch1=s1[2],ch2=s2[2];
    if(c1!=c2){
        ans1=ans2=ans3=ans4=false;
    }else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        ans1=true;
        ans2=ans3=ans4=false;
    }else if(('A'<=ch1&&ch1<='C'&&'D'<=ch2&&ch2<='E')||
             (('A'<=ch2&&ch2<='C'&&'D'<=ch1&&ch1<='E'))){
        ans1=ans2=true;
        ans3=ans4=false;
    }else if(ch1+1!=ch2&&ch2+1!=ch1){
        ans1=ans2=ans3=true;
        ans4=false;
    }else{
        ans1=ans2=ans3=ans4=true;
    }
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
