#include<bits/stdc++.h>
using namespace std;
int main(){
     freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    long long a,bj=0;
    string s;
    cin>>a;
    for(int i=1;i<=a;i++){
        long long  x;
        string y;
        cin>>x;
        cin>>y;
        for(long long i=1;i<=x;i++)
        s+=y;
        bj+=x;
    }
    if(bj%2==0){
        long long bj1=bj/2-1,bj2=0;
        for(long long i=bj/2;i<=bj;i++){
            if(s[i]!=s[bj1]){
                bj2++;
            }
            bj1--;
        }
        long long bj3=bj-1,bj4=0;
        for(long long i=1;i<=bj/2-1;i++){
            if(s[i]!=s[bj3]){
                bj4++;
            }
            bj3--;
        }
        if(bj2>bj4)
        cout<<bj2;
        else
            cout<<bj4;
    }
    else{
        long long bj1=bj/2-1,bj2=0;
        for(long long i=bj/2+1;i<=bj;i++){
            if(s[i]!=s[bj1]){
                bj2++;
            }
            bj1--;
        }
        long long bj3=bj-1,bj4=0;
        for(long long i=1;i<=bj/2-1;i++){
            if(s[i]!=s[bj3]){
                bj4++;
            }
            bj3--;
        }
        if(bj2>bj4)
        cout<<bj2;
        else
            cout<<bj4;
    }
    return 0;
}
