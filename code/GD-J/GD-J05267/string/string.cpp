#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    queue<char>arr;
    int flag=0;
    for(int i=1;i<=n;i++){
        int times=0;
        cin>>times;
        char s;
        cin>>s;
        for(int j=1;j<=times;j++){
            arr.push(s);
            flag++;
        }
    }
    int cnt=0;
    for(int l=1,r=flag;l<=r;l++,r--){
        if(arr.front()!=arr.back()){
            cnt++;
        }
        arr.pop();
    }

    cout<<cnt;
    return 0;
}
