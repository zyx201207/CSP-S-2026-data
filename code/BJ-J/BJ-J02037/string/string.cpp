#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char n,x;
    int a[1000011111];
    string s = '';
    int num=0;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> a[i] >> x;
        for(int j = 0; j < a[i]; j ++){
            s+=x;
        }
    }
    for(int i = 0; i < s.length(); i ++){
        if(s[i]==s[s.length()-1-i]){
            continue;
        }
        else{
            num++;
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    }
    cout <<  num;
    return 0;
}
