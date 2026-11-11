#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
int main(){
      freopen("string.in","r",stdin);
      freopen("string.out","w",stdout);
    cin >> n;
    for (int i=0;i<n;i++){
        long long   x;
        char h;
        cin >> x >> h;
        for(int i=0;i<x;i++){
            s+=h;
        }
    }
    long long cnt = 0;

    long long right = s.size();
    for (long long   i = 0;i< right;i++){
        if (s[i]==s[right]){
            right --;
            continue;
        }
        else {
            cnt++;
            right --;
        }

    }

cout <<cnt<<endl;

return 0;
}
