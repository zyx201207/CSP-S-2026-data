#include<iostream>
using namespace std;

int main(){

    string s;    cin>>s;
    for(int i=s.size();i>=1;i--){
        if(s[i]>='0'&&s[i]<='9'){
            cout<<s[i];
        }
    }
    return 0;
}

