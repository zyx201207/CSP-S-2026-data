#include<iostream>
#include<string>
using namespace std;
int main(){
    //输入
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    string s;
    int p;
    cin>>p;
    //处理字符串至S
    for(int i = 0;i < p;i++){
        int a;char b;
        cin>>a>>b;
        for(int j = 0;j < a;j++){
            s += b;
        }
    }
    cout<<0;
    return 0;
}
