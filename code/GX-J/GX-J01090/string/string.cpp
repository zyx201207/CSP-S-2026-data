#include <iostream>
#include <string>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int c;
    char zm1[n+5];
    long long all[26] = {0};
    for(int i = 0;i<n;i++){
        cin >> c >> zm1[i];
        int d = zm1[i] - 97;
        all[d] += c;
    }
    string a = "";
    long long sum = 0;
    for(int i = 0;i<26;i++){
        string b = "";
        sum += all[i];
        for(int j = 0;j<all[i];j++){
            char c = i + 97;
            b += c;
        }
        a += b;
    }
    long long half = sum / 2;
    string m = "";
    for(int i = 0;i<n/2;i++){
        string l = "";
        int ind = all[zm1[i]-97];
        for (int j = 0;j<ind/2;j++){
            l += zm1[i];
        }
        m += l;
        }
    }
    string l = m + "";
    for (int i = 0;i<n;i++){

    }



