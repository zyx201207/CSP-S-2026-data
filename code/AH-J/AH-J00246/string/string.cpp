#include<iostream>
#include<cstdio>
using namespace std;
int cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        while(x--){
            s+=y;
        }
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[n-i+1]){
            cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
