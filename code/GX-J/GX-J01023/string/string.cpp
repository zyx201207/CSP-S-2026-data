#include <bits/stdc++.h>
using namespace std;
const int N=1e8+2;
int str_int[N];
bool huiwen(string s){
    int tou=0,wei=s.size()-1,mid=(tou+wei)/2;
    while(tou<wei){
        if(s[tou]!=s[wei])return false;
        tou++;
        wei--;
    }
    return true;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    int sum=1;
    bool flag=0;
    string str,str1;
    char cr;
    int it;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>it>>cr;
        str_int[i]=it;
        for(int i=1;i<=it;i++)str+=cr;
    }
    if(huiwen(str)){
        cout<<"0";
        return 0;
    }
    else{
        for(int i=0;i<str.size();i++){
            if(str[i]==str[i+1])sum++;
            else{
                break;
            }
        }
    }
    cout<<sum;
	return 0;
}
