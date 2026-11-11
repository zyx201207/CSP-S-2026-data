#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int ln;char ls;
    for(int i=0;i<n;++i){
        cin >> ln >> ls;
        for(int j=0;j<ln;++j){
            s+=ls;
        }
    }
    long long outn=0;
    long long lenc=s.size();lenc/=2;long long len=s.size()-1;
    for(long long i=0,j=len;i<lenc&&j>lenc;++i){
        if(s[i]!=s[j]) outn++;
        j--;
    }
    cout << outn;
    return 0;
}
