#include<bits/stdc++.h>
using namespace std;
char cmp[10000000];long long mun=0;
int qwe(int r,int l){
    if(r>=l){
        return mun;
    }
    if(cmp[r]!=cmp[l]){
        mun++;
        r++;
        l--;
        qwe(r,l);
    }else{
        r++;
        l--;
        qwe(r,l);
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin>>a;
    long long b;
    char c;
    int num=0;
    for(int i=0;i<a;i++){
        cin>>b>>c;
        for(int j=0;j<b;j++){
            cmp[num]=c;
            num++;
        }
    }
    int r=0,l=num-1;
    cout<<qwe(r,l);
    return 0;
}
