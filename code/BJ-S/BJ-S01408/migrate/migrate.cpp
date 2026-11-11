#include<iostream>
#include<cstdio>
using namespace std;
int c,t,x[100000],num[10000],ab;
freopen("migrate.in",b,stdin);
void findans(){
    int n,d;
    getline(cin,n);
    getline(cin,d);
    for(int i=0;i<n;i++) {
        getline(cin,x[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(x[j-1]-x[i+1]>d)break;
            if(j-i>=2&&x[j+1]-x[i]>d){
                num[ab]+=j-i-1;
            }
        }
    }
}

int main(){

    getline(cin,c);
    getline(cin,t);

    for(ab=0;i<t;i++){
        findans();
    }
    for(int i=0;i<t;i++){
        freopen("migrate.out",num[ab],stdout);
    }
}
