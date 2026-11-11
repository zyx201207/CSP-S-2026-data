#include<bits/stdc++.h>
using namespace std;

//csp-s rp++

/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

const int maxn = 5e5 + 10;

int cards[maxn];
int CardsTheLast[maxn],IdTheLast[maxn],total[maxn];

inline bool Last(int id){
    return IdTheLast[id] == id;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> cards[i];
    }

    for(int i = n; i >= 1; i--) {
        if(CardsTheLast[cards[i]] == 0) CardsTheLast[cards[i]] = i;
        IdTheLast[i] = CardsTheLast[cards[i]];
    }

    for(int i = 1; i <= n; i++){
        for(int j = i ;j <= n; j++){
            j = IdTheLast[j];
            total[cards[j]]++;
        }
    }

    for(int i = 1; i <= m; i++){
        cout << total[i] << ' ';
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
