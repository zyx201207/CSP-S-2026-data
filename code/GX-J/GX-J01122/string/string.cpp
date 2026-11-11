#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    if(n==1){
        cout << 0;
        return 0;
    }
    string s;
    int minn=1000001;
    string sb = "";
    int cnt=0;
    while(n--){
        int a;
        cin >> a;
        minn = min(minn,a);
        cin >> s;
        for(int i = 1; i <= a; i++){
            sb+=s;
        }
    }
    for(int i = 0; i < sb.size(); i++) {
        if(sb[i]==sb[i+1]){
            cnt++;
        }
    }
    int c = sb.size();
    if(cnt==c-1){
        cout << 0;
        return 0;
    }
    if(c%2==1){
        cout << minn;
    }else{
        cout << 0;
    }
    return 0;
}
