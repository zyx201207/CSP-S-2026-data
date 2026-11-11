#include <bits/stdc++.h>
using namespace std;

const int N=1e5*2+5;
long long n;
string s="";
struct hw{
    long long a;
    char c;
}hg[N];

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    for (long long i=1;i <= n;i++){
        cin >> hg[i].a >> hg[i].c;
    }

    for (long long i=1;i <= n;i++){
        for (long long j=1;j <= hg[i].a;j++) {
            s.push_back(hg[i].c);
        }
    }

    //cout << s<<endl;
    long long j=s.size();
    long long sum=0;
    for (long long i=0;i < s.size()/2;i++) {
        j--;
        if (s[i] == s[j]) {
            //sum++;
        } else {
            sum++;
        }

    }

    cout  <<sum;
    return 0;
}
