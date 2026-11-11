#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int len=1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        for(int i=1;i<=x;i++){
            s[len]=c;
            len++;
        }
    }
    bool flag=true;
    for(int i=1;i<=(len+1)/2;i++){
        if(s[i]!=s[len-i]){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<cnt;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(int i=1;i<=(len+1)/2;i++){
        if(s[i]!=s[len-i]){
            cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
