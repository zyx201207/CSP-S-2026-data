#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r","stdin");
    freopen("card.out","w","stdout");
    long long n, m;
    cin >> n >> m;
    int ar[n], br[m];
    for (int i = 0; i < n; i++){
        cin >> ar[i];
    }
    for (int i = 0; i < m; i++){
        br[i] = i + 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i;j++){
            if(ar[j] ==ar[i]){
                for(int x = j + 1; x <= i; x++){
                    ar[x] = 0;
                }
            }
        }
    }
    for(int i = 0;i < m ;i++){
        if(ar[i]!=0){
	    br[ar[i]]++;
        }
    }
    for(int i = 0;i < m ;i++){
	cout <<br[i];
    }
   return 0;
}
