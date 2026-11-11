#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    int a,bj=0;
    string s;
    cin>>a;
    for(int i=1;i<=a;i++){
        int x;
        string y;
        cin>>x;
        cin>>y;
        for(int i=1;i<=x;i++)
        s+=y;
        bj+=x;
    }
    cout<<s;
    if(bj%2==0){
        int bj1=bj/2-1,bj2=0;
        for(int i=bj/2;i<=bj;i++){
            cout<<s[i]<<" "<<s[bj1]<<endl;
            if(s[i]!=s[bj1]){
                bj2++;
            }
            bj1--;
        }
        int bj3=bj-1,bj4=0;
        for(int i=1;i<=bj/2-1;i++){
            cout<<s[i]<<" "<<s[bj3]<<endl;
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
    if(bj%2!=0){
        int bj1=bj/2-1,bj2=0;
        for(int i=bj/2+1;i<=bj;i++){
            cout<<s[i]<<" "<<s[bj1]<<endl;
            if(s[i]!=s[bj1]){
                bj2++;
            }
            bj1--;
        }
        int bj3=bj-1,bj4=0;
        for(int i=1;i<=bj/2-1;i++){
            cout<<s[i]<<" "<<s[bj3]<<endl;
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
