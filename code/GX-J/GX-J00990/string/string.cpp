#include <bits/stdc++.h>
using namespace std;
string chuan;
long long quandeng(long long l,long long r){
    while(l<r){
        if(chuan[l]==chuan[r]){
            l++;
            r--;
        }else return false;
    }
    return true;
}
int main(){
    freopen ("string.in","r",stdin);
    freoprn ("string.out","w",stdout);
    long long a;
    long long b;
    string jia;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b>>jia;
        for(int i=1;i<=b;i++){
            chuan+=jia;
        }

    }
    long long l=0;
    long long r=chuan.size();
    if(quandeng(l,r)){
        cout<<0;
        return 0;
    }
    cout<<0;
    return 0;
}

