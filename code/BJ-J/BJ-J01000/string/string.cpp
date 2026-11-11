#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long num,ans;
int n;
struct node{
    int a;
    char c;
}s[maxn];


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> s[i].a >> s[i].c;
    }

    int a = 0,f = 0,j = n + 1;
    char c = ' ';
    for(int i = 1;i <= j;i++){
        j--;
        if(i > j)break;
        if(i == j){
            if(!(a == 0 || c == s[i].c))ans += a;
            break;
        }
        if(a == 0){
            if(s[i].c != s[j].c)ans += min(s[i].a,s[j].a);
            if(s[i].a >s[j].a){
                a = s[i].a - s[j].a;
                c = s[i].c;
                f = 0;
            }
            else{
                a = s[j].a - s[i].a;
                c = s[j].c;
                f = 1;
            }

        }
        else if(f == 0){
            if(a >= s[j].a){
                a -= s[j].a;
                if(c != s[j].c)ans += s[j].a;
                i--;
                continue;
            }
            if(c != s[j].c)ans += a;
            if(s[i].c != s[j].c){
                ans += min(s[i].a,s[j].a - a);
            }
            if(s[i].a + a > s[j].a){
                a = s[i].a + a - s[j].a;
                c = s[i].c;
                f = 0;
            }
            else{
                a = s[j].a - a - s[i].a;
                c = s[j].c;
                f = 1;
            }
        }
        else{
            if(a >= s[i].a){
                a -= s[i].a;
                if(c != s[i].c)ans += s[i].a;
                j++;
                continue;
            }
            if(c != s[i].c)ans += a;
            if(s[i].c != s[j].c){
                ans += min(s[i].a - a,s[j].a);
            }
            if(s[j].a + a > s[i].a){
                a = s[j].a + a - s[i].a;
                c = s[j].c;
                f = 1;
            }
            else{
                a = s[i].a - a - s[j].a;
                c = s[i].c;
                f = 0;
            }
        }
        //cout << a << ' ' << c << ' ' << f << ' ' << i << ' ' << j << ' ' << ans << endl;

    }
    cout <<ans;
    return 0;
}
