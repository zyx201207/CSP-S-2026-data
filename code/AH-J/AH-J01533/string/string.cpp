#include<bits/stdc++.h>
using namespace std;
int n , num = 0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    string s = " ";
    for(int i = 0;i < n;i++){
        string a;
        int b;
        cin >> b >> a;
        for(int j = 0;j < b;j++){
            s += a;
        }
    }
    int i = 0 , j = s.length() - 1;
    while(i < j){
        if(s[i] != s[j]){
            s[j] = s[i];
            num++;
        }
        i++;
        j--;
    }
    cout << num;
    return 0;
}

