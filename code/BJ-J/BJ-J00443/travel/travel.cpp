#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1,s2;
int s1n,s2n,a[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1n>>s1>>c2>>s2n>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s1n!=s2n){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(s1!='F')a[s1-'A'+1]++;
    if(s2!='F')a[s2-'A'+1]++;
    if(s1=='F')a[5]++;
    if(s2=='F')a[5]++;
    if(!((a[1]&&a[2])||(a[1]&&a[3])||(a[2]&&a[3])||(a[4]&&a[5]))){
        cout<<"00";
        return 0;
    }cout<<1;
    if(!((a[1]&&a[2])||(a[2]&&a[3])||(a[4]&&a[5]))){
        cout<<"0";
        return 0;
    }
    cout<<1;
    return 0;
}
