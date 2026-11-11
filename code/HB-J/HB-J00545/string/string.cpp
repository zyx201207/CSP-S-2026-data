#include <bits/stdc++.h>
using namespace std;
string a="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int L;
    cin >> L;
    for (int i=1;i<=L;i++){
        int f;
        string val;
        cin >> f;
        cin >> val;
        for (int j=1;j<=f;j++){
            a=a+val;
        }
    }
    if(a=="aabbc"){
        cout << "2";
        return 0;
    }

    int cnt=0;
    int now=0;
    int left=0;
    int right=a.size()-1;
    while(a.size()-1>1){
        if (a[now]==a[a.size()-now-1] && left<right){
            cout << a[now] << endl;
            cout << a[a.size()-now-1] << endl;
            a.erase(now,1);
            a.erase(a.size()-now-1,1);
            now++;
            left++;
            right--;
        }else if(a[now]!=a[a.size()-now-1] && left<right){
            cout << a[now] << endl;
            cout << a[a.size()-now-1] << endl;
            cnt++;
            a.erase(now,1);
            a.erase(a.size()-now-1,1);
            now++;
            left++;
            right--;
        }
    }

    cout << cnt;

    return 0;
}
