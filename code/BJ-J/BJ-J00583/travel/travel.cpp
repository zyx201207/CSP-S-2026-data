#include<iostream>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    long long ans1=0;
    long long ans2=0;
    long long ans3=0;
    long long ans4=0;
    long long c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;

    if(c1=c2){
        ans1+=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s1[1]){
        ans2+=1;
    }


    cout<<ans1<<ans2<<ans3<<ans4;


    return 0;
}
