#include <iostream>
using namespace std;

char ab[1000000005];
int main(){
    int n;
    cin >> n;
    int a[n+5]={};
    char b[n+5]={};
    string ab = "";
    int x=0;
    int c=0;
    for (int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        for(int m=x;m<a[i];m++) {ab[m] == b[i];}
        x += a[i];
    }
    for(int i=0;i<=ab.size()/2;i++){
        if(!(ab[i] == ab[ab.size()-i])) c++;
    }
    cout << c;
    return 0;
}