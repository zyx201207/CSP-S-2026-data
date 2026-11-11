#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
int a[500005];
int count[300005];
int desktop[300005];
int size;

void play(int turns) {
    size = 0;
    for (int i = turns; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < size; j++) {
            if (desktop[j] == a[i]) {
                size = j + 1;
                flag = true;
                break;
            }
        }
        if (!flag) {
            desktop[size++] = a[i];
        }
    }
    for (int i = 0; i < size; i++) {
        count[desktop[i]]++;
    }
}

int main() {
    freopen("./card.in", "r", stdin);
    freopen("./card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        play(i);
    }
    for (int i = 0; i < m; i++) {
        cout << count[i + 1] << ' ';
    }
    cout << endl;
    return 0;
}
