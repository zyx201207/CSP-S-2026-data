#include <bits/stdc++.h>
using namespace std;

queue<int> real_table, ftable;

bool inTable(int x)
{
    int tmp = 1,flag=0;
    while ((tmp || ftable.front()!=real_table.front()) && !real_table.empty()) {
        tmp = 0;
        if (ftable.front()==x) {
            flag = 1;
        }
        ftable.push(ftable.front());
        ftable.pop();
    }
    if (flag) return true;
    return false;
}
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, a[1000000], t, cnt[1000000];
    cin >> n >> m;
    t = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (t < n) {
        for (int i = t; i < n; i++) {
            if (!real_table.empty() && inTable(a[i])) {
                int f = real_table.front(), tmp = 1, z = 1;
                while (tmp || real_table.front()!=f) {
                    if (real_table.front()!=a[i] && z) {
                        real_table.push(real_table.front());
                        ftable.push(ftable.front());
                        z=0;
                    }
                    real_table.pop();
                    ftable.pop();
                }
            }
            real_table.push(a[i]);
            ftable.push(a[i]);
            //cout << real_table.front() << " " << real_table.back()<<endl;
        }
        while (!real_table.empty()) {
            cnt[real_table.front()]+=1;
            //cout << real_table.front() << endl;
            real_table.pop();
            ftable.pop();
        }
        t++;
    }
    for (int j = 1; j <= m; j++) {
        cout << cnt[j] << " ";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
