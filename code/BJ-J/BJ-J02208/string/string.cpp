#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s = "";
    int nn = 0;
    cin >> nn;
    for(int i = 1;i<=nn;i++) {
        int aa;
        cin >> aa;
        char bb;
        cin >> bb;
        for(int j = 1;j<=aa;j++) {
            s+=bb;
        }
    }
    //"mid" is right's beginning when s.length%2==0
    //"mid" is middle when s.length%2==1
    int mid = -1;
    mid = s.length()/2;

    if(s.length() == 1) {
        cout << 0;
        return 0;
    }

    string right = "",left = "";
    if (s.length()%2 == 0){
        right = s.substr(mid,mid);
        left = s.substr(0,mid);
    }else{
        right = s.substr(mid+1,mid);
        left = s.substr(0,mid);
    }

    string lefta = left;
    string righta = right;
    for(int i = 0;i<left.length();i++) {
        lefta[i] = left[left.length()-1-i];
    }
    for(int i = 0;i<right.length();i++) {
        righta[i] = right[right.length()-1-i];
    }
    if(lefta == right){
        cout << 0;
        return 0;
    }

    int cnt1 = 0,cnt2 = 0;
    for(int i = 0;i<left.length();i++) {
        if(left[i] != righta[i]) {
            cnt1++;
        }
    }
    for(int i = 0;i<=right.length();i++) {
        if(right[i]!=lefta[i]) {
            cnt2++;
        }
    }
    int cnt = max(cnt1,cnt2);
    cout<<cnt;
    return 0;
}
