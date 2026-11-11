#include <bits/stdc++.h>
using namespace std;
long long a[200005];
string h(int k){
    string s="";
    while(k != 0){
        if(k%2 ==0)s+='0';
        else s+='1';
        k /= 2;
    }
    return s;
}
long long power1(int a,int b){
    long long dddd = 1;
    for(int i = 1;i <= b;i++){
        dddd*= a;
    }
    return dddd;


    }
long long adn(string w1,string w2){
    int len = min(w1.size(),w2.size());
    string y="";
    for(int i = 0;i < len;i++){
        if(w1[i]=='1'&&w2[i] == '1')
            y+='1';
        else y +='0';
    }
    long long last = 0;
    for(int i = 0;i < len;i++){
        if(y[i] == '1')last+=power1(2,i);
    }
    return last;
}
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    long long maxn = 0;
    if(m == 2){
    for(int i = 1;i <= n;i++){
        for(int j = i+1;j<= n;j++){
            if(adn(h(a[i]),h(a[j]))> maxn){
                maxn = adn(h(a[i]),h(a[j]));
            }
        }
    }
    cout<<maxn;
    }
    else if(m == 1){
        for(int i  = 1;i <= n;i++){
            maxn =max(maxn,a[i]);
        }
        cout<<maxn;
    }

    else if(m == n){
        int l = a[1];
        for(int i = 2;i<= n;i++){
            l =adn(h(l),h(a[i]));
        }
        cout<<l;
    }
    else if(m == 3){
        int k1= 1,k2 = 1;
        for(int i = 1;i <= n;i++){
        for(int j = i+1;j<= n;j++){
            if(adn(h(a[i]),h(a[j]))> maxn){
                if(adn(h(a[i]),h(a[j]))>maxn){
                    k1 = i;k2 = j;
                    maxn = adn(h(a[i]),h(a[j]));
                }

            }
        }
    }
    int maxn1 = maxn;
    for(int i = 1;i <= n;i++){
        if(i != k1&&i != k2){
            maxn = max(maxn,adn(h(maxn1),h(a[i])));
        }
    }
    cout<<maxn;
}
else {
    return 0;
}





    return 0;
}
