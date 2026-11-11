#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,b=0,sum=0;
    string s;
    char c;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> c;
        b+=a;
    }
    for(int i=1;i<=a;i++){
        s+=a;
    }
    int i,j;
    i=0;
    j=b;
    while(i<=j){
        if(s[i]==s[j]){
            i++;
            j++;
        }
        if(s[i]!=s[j]){
            sum+=1;
            i++;
            j--;
        }
    }
    cout << sum-1;


    return 0;
}
