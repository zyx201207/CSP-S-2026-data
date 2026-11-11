#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string str;
    long long cnt=0;
    for(int i=0;i<n;i++){
        int a;
        char b;
        cin>>a>>b;
        for(int j=0;j<a;j++){
            str.push_back(b);
        }
    }
    for(int i=0,j=str.size()-1;i>j;i++,j--){
        if(str[i]!=str[j]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
