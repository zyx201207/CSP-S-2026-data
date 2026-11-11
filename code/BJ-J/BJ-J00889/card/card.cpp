#include<bits/stdc++.h>
using namespace std ;
int main(){
    freopen("card.in","r",stdin) ;
    freopen("card.out","w",stdout) ;
    int n ;
    cin >> n ;
    int m ;
    cin >> m ;
    vector<int> shu(n) ;
    for(int i = 0 ; i < n ; i++){
        cin >> shu[i] ;
    }
    int p = 0 ;
    int z ;
    int g ;
    vector<int> shu2(n) ;
    vector<int> geshu(n) ;
    for(int i = 0 ; i < n ; i++){
        geshu[i] = 0 ;
    }
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            shu2[j] = shu[j] ;
        }
        for(int j = i + 1 ; j < n ; j++){
            for(int l = 0 ; l <= i ; l++){
                if(shu2[l] = shu2[j]){
                    z = 0 ;
                    p = l ;
                    g = l ;
                    while(p >= 0){
                        shu[z] = shu[g] ;
                        g++ ;
                        z++ ;
                        p-- ;
                    }
                    for(int o = l ; o < j ; i++){
                        shu2[i] = 0 ;
                    }
                }

            }
        }
        for(int l = 0 ; l < n ; l++){
            for(int j = 0 ; j < n ; j++){
                if(shu[j] == l){
                    geshu[l]++ ;
                }
            }
        }


    }
    for(int i = 0 ; i < n ; i++){
        if(geshu[i] != 0){
            cout << geshu[i] << endl ;
        }
    }
    return 0 ;
    fclose(stdin) ;
    fclose(stdout) ;
}
