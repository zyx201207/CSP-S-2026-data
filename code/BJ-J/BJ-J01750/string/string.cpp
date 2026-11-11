#include<bits/stdc++.h>
using namespace std;
string str = "";
int n;
const int N = 2e5 + 5;
int a[N],b[N];
long long d1[N],d2[N];
char c[N],c1[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int maxa = 0;
    for(int i = 1;i <= n;i++){
        int num;
        char ch;
        cin >> num >> ch;
        a[i] = num;
        c[i] = ch;
        for(int j = 1;j <= num;j++){
            str += ch;
        }
        if(num > maxa) maxa = num;
        d1[i] = d1[i - 1] + a[i];
    }
    for(int i = n;i >= 1;i--){
        b[i] = a[n - i + 1];
        c1[i] = c[n - i + 1];
        d2[i] = d2[i - 1] + b[i];
    }
    string s = str;
    reverse(s.begin(),s.end());
    long long cnt = 0;
        for(int i = 0;i < str.size() / 2;i++){
            if(str[i] != s[i]){
                cnt++;
            }
        }
        //cnt /= 2;
        cout << cnt << endl;

        int cura = 0,curb = 0;
    return 0;
}
