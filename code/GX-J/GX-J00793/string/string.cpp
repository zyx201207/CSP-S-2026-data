#include <bits/stdc++.h>
using namespace std;
int acount[200000];
char s[200000];
long long total = 0;
int n;
char search(long long index){
    long long res = 0;
    for(int i = 0;i<n;i++){
        if(res <= index && index < res+acount[i])return s[i];
        else res += acount[i];
    }
}
int main(){
    fstream input;
    fstream output;
    input.open("string.in",ios_base::in);
    output.open("string.out",ios_base::out);
    input >> n;
    for(int i = 0;i<n;i++){
        input >> acount[i] >> s[i];
        total += acount[i];
    }
    long long res = 0;
    for(long long i = 0;i<total/2;i++){
        res += !(search(i) == search(total-1-i));
    }
    output << res;
    input.close();
    output.close();
    return 0;
}