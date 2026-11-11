#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdout);
    int a , b;
    cin >> a >> b;
    int n[a] , t[b];
    for(int i = 1; i <= b; i++){
        t[i] == 0;
    }
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }
    for(int z = 0; z < a; z++){
        int m[a];
        for(int i = z; i < a; i++){
            for(int j = 0; j < i - 1; j++){
                if(n[i] == n[j]){
                    for(int s = j; s < i - 1; s++){
                        m[s] = 0;
                    }
                }
            }
            m[i] = n[i];
        }
        for(int i = 0; i < a; i++){
            if(m[i] != 0){
                for(int j = 1 , j <= b; j++){
                    if(m[i] == j){
                        t[j]++;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= b; i++){
        cout << t[i];
    }
    return 0;
}

