#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);

    int n , m;
    cin >> n >> m;
    vector<int>card(n);
    vector<int>Count(m+1 , 0);
    for (int i = 0 ; i < n ; i++){
        cin >> card[i];
    }
    int already = 0;
    while(already < n){
        vector<int>temp(n-already , 0);
        int index = 0;
        auto _find = [&index , &temp](int num){
            for (int i = 0 ; i < temp.size() ; i++){
                if (temp[i] == num){
                    index = i+1;
                    for (int j = i+1 ; j < temp.size() ; j++){
                        temp[j] = 0;
                    }
                    break;
                }
            }
        };
        for (int i = already ; i < n ; i++){
            temp[index] = card[i];
            index++;
            _find(card[i]);
        }
        for (int i = 0 ; i < temp.size() ; i++){
            Count[temp[i]]++;
        }
        already ++;
    }

    for (int i = 1 ; i <= m ; i++){
        cout << Count[i] << " ";
    }
    return 0;
}
