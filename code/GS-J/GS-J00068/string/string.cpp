#include<bits/stdc++.h>
using namespace std;
bool ifhuiwen(string lc){
    string temp=lc;
    reverse(lc.begin(),lc.end());
    if(temp==lc){
        return true;
    }
    return false;
}
int n,op,l,r,cnt;
string s,chuan;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //One:cin and conncet
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op>>s;
        for(int i = 1;i<=op;i++){
            chuan+=s;
        }
    }
    //Two if chuan is a huiwen,return 0
    if(ifhuiwen(chuan)){
        cout<<0;
        return 0;
    }
    //Three:if begin and tail
    int len=chuan.size();
    l=1;
    r=len;
    for(int i =1;i<=len;i++){
        if(chuan[l]==chuan[r]){
            l++;
            r--;
        }
        else{
            chuan[r]=chuan[l];
            cnt++;
            l++;
            r--;
        }
        if(l>=r){
            break;
        }
    }
    cout<<cnt;
    return 0;
}

