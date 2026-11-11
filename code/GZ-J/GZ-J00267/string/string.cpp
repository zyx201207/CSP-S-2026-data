//GZ-J00267 贵阳市观山湖区第一高级中学 曹映森
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    vector<char> c;
    vector<long long> t;
    long long n;
    cin>>n;
    for(long long i=0;i<n;i++){
        long long ttmp;
        char ctmp;
        cin>>ttmp>>ctmp;
        t.push_back(ttmp);
        c.push_back(ctmp);
    }
    string s="";
    for(long long i=0;i<n;i++){
        for(long long j=0;j<t[i];j++){
            s+=c[i];
        }
    }
    long long cnt=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
