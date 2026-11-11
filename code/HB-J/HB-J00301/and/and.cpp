#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

vector<long long> a(1);

long long dfs(const int& n,const int& m,int x = 1,int selected = 0,long long ans = -0x3f3f3f3f) {
    if (selected >= m) return ans;
    if (x >= n) return -0x3f3f3f3f;
    long long ansa = dfs(n,m,x + 1,selected + 1,(ans & (a[x])));
    long long ansb = dfs(n,m,x + 1,selected,ans);
    return max(ansa,ansb);
}

int main(int argc,char* argv[]) {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }

    if (m == 1) {
        cout << *max_element(a.begin(),a.end());
    }
    else if (m == 2) {
        long long maxn = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                maxn = max((a[i] & a[j]),maxn);
            }
        }
        cout << maxn;
    }
    else {
        cout << dfs(n,m);
        // I don't hope this fucking depth first search function can work.
        // I am not angry whether it can bring me some scores or not.
        // Because I hope my program can work when m = 1 or 2.
    }

    return EXIT_SUCCESS;
}

// get score 16
