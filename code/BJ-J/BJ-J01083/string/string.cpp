#include<iostream>
using namespace std;
char b[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a = " ";
    string s;
    int c;
    int n;
    cin >> n;
    for(int i = 0;i <= n;i++){
        cin >> c >> s;
        for(int i = 0;i <= c;i++){
            a += s;
        }
    }
    int x = 0,cnt = 0;
    for(int i = a.size();i >= 0;i--){
        b[i] = a[x];
        x++;
    }
    for(int i = 0;i <= a.size();i++){
        if(a[i] != b[i]){
            cnt++;
        }
    }
    cout << cnt;
}