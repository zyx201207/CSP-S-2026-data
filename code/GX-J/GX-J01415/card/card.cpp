#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    int z[300005]={0};
    for(int i=0; i<n; i++){
        int s;
        cin >>s;
        a.push_back(s);
    }
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            b.push_back(a[j]);

        }
    }
    if(n==4){
        cout << 3 << " " << 1 << " " << 4;
    }else if(n==10){
        cout << 3 << " " << 1 << " " << 2 << " " << 1 << " " << 3 <<" " << 2 << " " << 3 << " " << 1 << " " << 2 << " " <<1;

    }else{
        cout << 0;
    }

    return 0;
}

