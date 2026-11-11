#include<bits/stdc++.h>
using namespace std;
//long long  a[10000009][100000000];
string s;
string b;
bool ch(string x){
    string  ans;
    for(int i=x.size();i>=1;i--){
        ans +=x[i];
    }
    if(ans==x){
        return true;
    }
    else{
        return false;
    }


}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a;
    long long sum=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        for(int j=1;j<=a;j++){
            s+=b;

        }
    }

    for(int i=n;i>=1;i--){
        if(ch(s)){
            cout << sum;
            return 0;
        }
        s[i]=s[1];
        sum++;
}



    return 0;
    }
