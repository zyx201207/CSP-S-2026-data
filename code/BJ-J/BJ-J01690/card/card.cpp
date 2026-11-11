#include<iostream>
using namespace std;
int z[100000] = { };
int n,m,t;
int b(int x){
    for(int l = 0;l <= n;l++){
        if(z[l] == x){
            for(int j = l;j <= n;j++){
                z[j] = 0;
            }
            z[l] = x;
            t = l+1;
            return 1;
        }
    }
    t++;
    return 0;
}
int zz(){
    cout << "z: ";
    for(int e = 0;e <= 10;e++){
        cout << z[e] << " ";
    }
    cout << endl;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    int p[n] = { };
/*
    cout << "p: ";
    for(int e = 0;e <= 10;e++){
        cout << p[e] << " ";
    }
    cout << endl;
*/
    int pp[n] = { };
    for(int i = 0;i < n;i++){
        cin >> p[i];
/*
        cout << "p: ";
        for(int e = 0;e <= 10;e++){
            cout << p[e] << " ";
        }
        cout << endl;
*/
    }
    t = 0;
/*
    cout << "p: ";
    for(int e = 0;e <= 10;e++){
        cout << p[e] << " ";
    }
    cout << endl;
*/
    for(int o = 0;o <= n;o++){
        for(int i = o; i<= n;i++){
            z[t] = p[i];
            b(p[i]);
            pp[p[i]]++;
            //zz();
        }
    }
    for(int i = 0;i <= n;i++){
        cout << pp[i] << " ";
    }
    return 0;
}