#include<bits/stdc++.h>
using namespace std;
long long a,n,cnt,k=0;
string s,b;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin >> a;
    cnt=0;
    for(int j=1;j<=a;j++){
        cin>>n;
        cin>>b;
        for(int i=n;i>=1;i--){
            s[k]=b[1];
            k+=1;
        }
    }
    for(int i=1;i<=(s.size()/2);i++){
        for(int j=s.size();j>=s.size()/2;j--){
            if(s[i]!=s[j]){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
