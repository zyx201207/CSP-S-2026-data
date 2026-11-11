#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string str="";
    int n;
    cin>> n;
    for(long long i=0; i<n; i++){
        long long j;
        char a;
        cin>> j >> a;
        while(j>0){
            str+=a;
            j--;
        }
    }
    int sum = 0;
    for(int i = 0; i<str.length()/2;i++){
        if(str[i] != str[str.length()-1-i]){
            sum++;
            str[str.length()-1-i]=str[i];
        }
    }
    cout<< sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
