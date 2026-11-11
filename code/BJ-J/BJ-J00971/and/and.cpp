#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m; cin >> n >> m;
    //
    long long tempmisone = -1;
    long long anweiyuans;
    long long tempmistwo = -1;
    long long tempmisthree = -1;
    long long tempmisfour = -1;
    long long tempmisfive = -1;
    long long tempmissix = -1;
    long long tempmisseven = -1;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        tempmisone = max(1LL * tempmisone, a[i]);
    }
    anweiyuans = a[1];
    for(int i=2; i<=n; i++) {
        anweiyuans = anweiyuans & a[i];
    }

    for(int i=1; i<n; i++) {
        for(int j = i+1; j <= n; j++) {
            long long temp = a[i] & a[j];
            tempmistwo = max(tempmistwo, temp);
        }
    }
    for(int i=1; i<n; i++) {
        for(int j=i+1; j < n; j++) {
            for(int k = j+1; k <= n; k++) {
                long long tempp = a[i] & a[j] & a[k];
                tempmisthree = max(tempmisthree, tempp);
            }
        }
    }
    for(int i=1; i<n; i++) {
        for(int j=i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                for(int l = k+1; l <=n; l++) {
                    long long temppp = a[i] & a[j] & a[k] & a[l];
                    tempmisfour = max(tempmisfour, temppp);
                }

            }
        }
    }

    for(int i=1; i<n; i++) {
        for(int j=i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                for(int l = k+1; l <n; l++) {
                    for(int x = l+1; x <= n; x++) {
                        long long tempppp = a[i] & a[j] & a[k] & a[l] & a[x];
                        tempmisfive = max(tempmisfive, tempppp);
                    }
                }

            }
        }
    }


    for(int i=1; i<n; i++) {
        for(int j=i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                for(int l = k+1; l <n; l++) {
                    for(int x = l+1; x< n; x++) {
                            for(int y = m+1; y <= n; y++) {

                                long long temppppp = a[i] & a[j] & a[k] & a[l] & a[m] & a[x] & a[y];
                                tempmissix = max(tempmissix, temppppp);
                            }
                    }
                }

            }
        }
    }

    for(int i=1; i<n; i++) {
        for(int j=i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                for(int l = k+1; l <n; l++) {
                    for(int x = l+1; x<= n; x++) {
                            for(int y = x+1; y < n; y++) {
                                    for(int z = y + 1; z <= n; z++) {

                                            long long tempppppp = a[i] & a[j] & a[k] & a[l] & a[m] & a[x] & a[y] & a[z];
                                            tempmisseven = max(tempmisseven, tempppppp);
                                    }

                            }
                    }
                }

            }
        }
    }

    if(m == 1) {
        cout << tempmisone;
        return 0;
    }
    else if(m == 2) {
        cout << tempmistwo;
        return 0;
    }
    else if(m == 3) {
        cout << tempmisthree;
        return 0;
    }
    else if(m == 4) {
        cout << tempmisfour;
        return 0;
    }
    else if(m == 5) {
        cout << tempmisfive;
        return 0;
    }
    else if(m == 6) {
        cout << tempmissix;
        return 0;
    }
    else if(m == 7) {
        cout << tempmisseven;
        return 0;
    }
    else if(m == n) {
        cout << anweiyuans;
        return 0;
    }
    else {
        cout << 1;
        return 0;
    }




    //
    return 0;
}

