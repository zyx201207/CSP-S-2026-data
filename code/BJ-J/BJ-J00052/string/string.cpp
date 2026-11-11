#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    bool flag=false;
    char last='0';
    string ch;
    while(n--){
        int a;
        char b;
        cin>>a>>b;
        if(last!='0'&&last!=b&&!flag){
            flag=true;
        }
        last=b;
        for(int i=0;i<a;i++){
            ch.push_back(b);
        }
    }
    if(!flag){
        cout<<0<<endl;
        return 0;
    }
    unsigned long long l=0,r=ch.size()-1;
    int cnt=0;
    while(l<=r){
        if(ch[l]!=ch[r]){
            cnt++;
        }
        l++,r--;
    }
    cout<<cnt<<endl;
    return 0;
}

