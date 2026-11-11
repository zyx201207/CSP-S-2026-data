#include <bits/stdc++.h>
using namespace std;
bool pd(string s){
    long long l=s.size();
    string sub1,sub2;
    if (l&1){
        sub1=s.substr(0,l/2),sub2=s.substr((l/2)+1);
        reverse(sub2.begin(),sub2.end());
        if (sub1==sub2) return 1;
        else return 0;
    }
    else {
        sub1=s.substr(0,l/2),sub2=s.substr(l/2);
        reverse(sub2.begin(),sub2.end());
        if (sub1==sub2) return 1;
        else return 0;
    }
}
long long l,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >>n;
    for (int i=1;i<=n;i++){
        int x;
        char c;
        cin >>x>>c;
        l+=x;
        while (x--){
            s+=c;
        }
    }
    if (pd(s)==1) {
        cout <<0;
        return 0;
    }
    else {
        string sub1,sub2;
        if (l&1){
            sub1=s.substr(0,l/2),sub2=s.substr((l/2)+1);
            reverse(sub2.begin(),sub2.end());
            for (int i=0;i<l/2;i++){
                if (sub1[i]!=sub2[i]) ans++;
            }
        }
        else {
            sub1=s.substr(0,l/2),sub2=s.substr(l/2);
            reverse(sub2.begin(),sub2.end());
            for (int i=0;i<l/2;i++){
                if (sub1[i]!=sub2[i]) ans++;
            }
        }
    }
    cout <<ans;
    return 0;
}
