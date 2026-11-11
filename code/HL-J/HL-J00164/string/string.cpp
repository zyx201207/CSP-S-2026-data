#include<bits/stdc++.h>
using namespace std;
string s;
int n,a,x,f[30],ans;
unsigned long long sum=0;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        f[c-'a'+1]++;
        sum+=a;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    for(int i=1;i<=25;i++){
        if(f[i]!=0){
            ans++;
        }
    }
    if(ans==1){
        cout << 0;
        return 0;
    }
    if(sum%2!=0){
        int num = 0;
        for(int i=0;i<(sum-1)/2;i++){
            if(s[i]!=s[sum-i-1]){
                num++;
            }
        }
        cout << num;
    }else{
        int num = 0;
        for(int i=0;i<(sum-1)/2;i++){
            if(s[i]!=s[sum-i-1]){
                num++;
            }
        }
        cout << num;
    }
    return 0;
}
