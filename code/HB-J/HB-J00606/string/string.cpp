#include<bits/stdc++.h>
using namespace std;

string s[10005];
bool cmp(string a,string b){
    return a+b>b+a;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,c,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>c;
    }
    sort(s+1,s+1+n,cmp);
    string res;
    for(int i=n;i>=1;i--){
        res+=s[i];
        if(res!=s[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
