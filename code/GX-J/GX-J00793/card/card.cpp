#include <bits/stdc++.h>
using namespace std;
int card[300000];
int state[300000];
int cardTOP = 0;
int desk[500000];
int a[500000];
int n,m;
int group(int p){
    int deskTOP = 0;
    for(int i = p;i<n;i++){
        // a[i]
        for(int j = 0;j<deskTOP;j++){
            if(desk[j] == a[i]){
                deskTOP = j;
                break;
            }
        }
        desk[deskTOP] = a[i];
        deskTOP++;
    }
    for(int i = 0;i<deskTOP;i++){
        // cout << desk[i];
        for(int j = 0;j<m;j++){
            if(card[j] == desk[i]){
                state[j]++;
                break;
            }
        }
    }
    // cout << endl;
}
int main(){
    fstream input;
    fstream output;
    input.open("card.in",ios_base::in);
    output.open("card.out",ios_base::out);
    input >> n >> m;
    for(int i = 0;i<n;i++){
        input >> a[i];
        int f = 0;
        for(int j = 0;j<cardTOP;j++){
            if(card[j] == a[i]){
                f = 1;
                break;
            }
        }
        if(f == 0){
            card[cardTOP] = a[i];
            cardTOP++;
        }
    }
    sort(card,card+m);
    for(int i = 0;i<m;i++){
        state[i] = 0;
    }
    for(int i = 0;i<n;i++){
        group(i);
    } 
    for(int i = 0;i<m;i++){
        output << state[i] << " ";
    }
    // cout << a[0] << a[1] << a[2] << endl;
    input.close();
    output.close();
    return 0;
}