#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll hw(string b){
    string t=b;
    reverse(b.begin(),b.end());
    if(b==t){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    string b;
    for(int i=1;i<=n;i++){
        int a;string s;
        cin >> a >> s;
        for(int j=1;j<=a;j++){
            b+=s;
        }
    }
    ll sum=0;
    if(hw(b)) cout << 0;
    else{
        for(int i=1;int j=b.size();i<=b.size()){
            if (b[i]==b[j]) j--,i++;
            else{
                b[j]=b[i]; sum+=1;
            }
        }
        if(hw(b)) cout << sum << endl;
    }


    return 0;
}
