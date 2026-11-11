#include <iostream>
#include <cstdio>
using namespace std;

string s1=" ", s2=" ";
int cnt, n, x, m;
char c;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x >> c;
        while(x--){
            s1+=c;
            s2+=' ';
        }
    }
    m=s1.size()-1;
    for(int i=1; i<=m; i++)
        s2[m-i+1]=s1[i];
    if(s1==s2){
        cout << 0 << endl;
        return 0;
    }
    for(int i=1; i<=(m+1)/2; i++){
        if(s1[i]==s2[i])
            continue;
        cnt++;
        s1[m-i+1]=s1[i];
        s2[i]=s1[i];
    }
    cout << cnt << endl;
    return 0;
}