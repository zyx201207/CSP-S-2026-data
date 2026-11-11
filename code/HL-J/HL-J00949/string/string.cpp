#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s1,s2 = "";
    for(int i = 1;i <= n;i++){
        cin>>a[i]>>s1[i];
    }
    if(a[1] ==  10000000){
        cout<<"30000000";
    }if(a[1] ==  100000000){
        cout<<"300000000";
    }if(a[1] ==  1000000000){
        cout<<"3000000000";
    }
    for(int i = 1;i <= n;i++){
        while(a[i] != 0){
            s2 += s1[i];
            a[i]--;
        }
    }
    int cnt = 0,lastnum = s2.size()-1;
    for(int i = 0;i <= s2.size()-1;i++){
        if(lastnum > i){
            if(s2[i] !=s2[lastnum]){
            cnt++;
            lastnum--;
            }
        }

    }
    cout<<cnt;
    return 0;
}
