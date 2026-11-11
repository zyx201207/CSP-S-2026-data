#include<bits/stdc++.h>
#define fro(i,a,b) for(long long (i)=(a);(i)<=(b);(i)++)
using namespace std;
int n,ans;
long long l;
int a[200005];
char c[200005];
long long s[200005];
char find_(long long id) {
    fro (i,1,n) {
        if (s[i] >= id) {
            return c[i];
        }
    }
}

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    fro (i,1,n) {
        cin >> a[i] >> c[i];
    }
    fro (i,1,n) {
        s[i] = s[i-1] + a[i];
    }
    //-----------------special judge---------------------
    if (s[n/2] == s[n]-s[n/2]) {
            bool p = true;
        fro (i,1,n/2) {
            if (c[i] == c[n-i+1]) {
                p = false;
                break;
            }
        }
        if (p) {
            cout << s[n/2];
            return 0;
        }
    }
    //---------------------------------------------------
    if (s[n] % 2 == 1) {
        fro (i,1,n) {
            if (s[i] >= (s[n]+1)/2) {
                a[i]--;
                break;
            }
        }
    }
    fro (i,1,n) {
        s[i] = s[i-1] + a[i];
    }
    l = s[n];
    int s_ = l%2==1 ? (l+1)/2 : l/2;
    fro (i,1,s_) {
        if (find_(i) != find_(l-i+1)) ans++;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
