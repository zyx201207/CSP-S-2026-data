#include<bits/stdc++.h>
using namespace std;

int card[500005] = {0},ju[500005] = {0},awnser[300005] = {0};
int in_ju[300005] = {0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m,right = 0;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> card[i];
    }
    for(int i = 0;i < n;i++){
        memset(ju,0,sizeof(ju));
        memset(in_ju,0,sizeof(in_ju));
        right = 0;
        for(int j = i;j < n;j++){
            if(in_ju[card[j]]){
                for(int k = in_ju[card[j]];k < right;k++){
                    in_ju[ju[k]] = 0;
                    ju[k] = 0;
                }
                right = in_ju[card[j]];
            } else {
                in_ju[card[j]] = ++right;
                ju[right - 1] = card[j];
            }
            /*
            cout << "of_ju: ";
            for(int x = 0;x < right;x++){
                cout << ju[x] << ' ';
            }
            cout << endl << "in_ju: ";
            for(int x = 1;x <= m;x++){
                cout << in_ju[x] << ' ';
            }
            cout << endl;
            //*/
        }
        for(int j = 0;j < right;j++){
            awnser[ju[j]]++;
        }
        /*
        cout << "awnser: ";
        for(int x = 1;x <= m;x++){
            cout << awnser[x] << ' ';
        }
        cout << endl;
        //*/
    }
    for(int x = 1;x <= m;x++){
        cout << awnser[x] << ' ';
    }
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}