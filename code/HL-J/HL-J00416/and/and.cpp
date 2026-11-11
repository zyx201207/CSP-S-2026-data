#include<bits/stdc++.h>
#define int long long
using namespace std ;
int counter[33] ;
int a[20001];
int m , n ;
int xxxxx = 0 ;

int mpow(int p){
    int ans = 1 ;
    for(int i = 1 ; i <= p ; i++){
        ans*=2 ;
    }
    return p ;
}

void setzero(){
    for(int i = 0 ; i <= 32 ; i++){
        counter[i] = 0 ;
    }
}

void count_(int modi){
    for(int i = 1 ; i <= n ; i++){
    	int xx = 1 ;
        for(int j = 1 ; j <= modi ; j++){
        	xx*=2 ;
           counter[j] += ((a[i]/xx)%2) ;
        }
    }
}

int and_(int x){
    setzero();
    count_(x);
    if(xxxxx == 1)for (int i = 1 ; i <= 32 ;i++)cout << counter[i] << endl ;
    if(x<=0)return 0 ;
    for(int i = x ; i>=1 ;i--){
        if(counter[i]>=m){
        	if(xxxxx == 1)cout << i <<"&&&&"<<counter[i]<<"&&&&\n";
            for(int k = 1 ; k <= x ; k++){
                if(!(a[k]&mpow(i))){
                   a[k] = 0 ;
                }
            }
            return and_(i-1)+mpow(i);
        }
    }
    return 0 ;
}


signed main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m ;
    for(int i = 1 ;i <= n ; i++){
        cin >> a[i] ;
    }
    cout << and_(32);
    return 0 ;
}

