#include<bits/stdc++.h>
using namespace std;
char a[100] = {'q','A','B','C'},b[50] = {'q','E','F'};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
    }
    else{
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    int l1 = 0,l2 = 0;
    for(int i = 0;i < s1.size();i++){
        if(s1[i] >= '0' && s1[i] <= '9'){
            l1 *= 10;
            l1 += int(s1[i] - '0');
        }
    }
    for(int i =0;i < s2.size();i++){
        if(s2[i] >= '0' && s2[i] <= '9'){
            l2 *= 10;
            l2 += int(s2[i] - '0');
        }
    }
    char z1 = s1[s1.size()-1],z2 = s2[s2.size()-1];
    if(l1 == l2){
        cout << 1;
    }
    else{
        cout << 0 << 0 << 0;
        return 0;
    }
    for(int i = 1;i <= 3;i++){
        if(a[i] == z1){
            if(a[1] == z2 || a[2] == z2 || a[3] == z2){
                cout << 1;
            }
            else{
                cout << 0 << 0;
                return 0;
            }
        }
    }
    if(z1 == b[1] || z1 == b[2]){
        if(z2 == b[1] || z2 == b[2]){
            cout << 1 << 1;
            return 0;
        }
        else{
            cout << 0 << 0;
            return 0;
        }
    }
    if(a[1] == z1 && a[3] == z2){
        cout << 0;
        return 0;
    }
    else if(a[1] == z2 && a[3] == z1){
        cout << 0;
        return 0;
    }
    else{
        cout << 1;
    }
    return 0;
}
