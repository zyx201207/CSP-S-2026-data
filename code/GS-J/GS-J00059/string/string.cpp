#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,t1,t2,t2_h;
    cin>> n;
    char temp;
    vector<char> s;
    for(int i=0;i<n;i++){
        cin >> t1;
        cin >> temp;
        for(int j=0;j<t1;j++){
        s.push_back(temp);
        }
    }
    t1 = 0;
    t2 = s.size();
    t2_h = t2 / 2;
    for(int i = 0;i<t2_h;i++){
        if (s[i] != s[t2-i]){
            t1++;
        }
    }
    cout << t1;
    return 0;
}
