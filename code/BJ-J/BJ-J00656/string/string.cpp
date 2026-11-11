#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
string s;
long long ssize=0,ans=0,n;

int to_string(){
    int mid=ssize/2;
    if(ssize%2==1){
        mid--;
    }
    for(int i=0;i<mid;i++){
        if(s[i]!=s[ssize-i-1]){
            ans++;
        }
    }
    return ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long x1,i=0;
    char x2;
    for(int j=0;j<n;j++){
        cin>>x1>>x2;
        ssize+=x1;
        while(x1--){
            s[i]=x2;
            i++;
        }
    }
    cout<<to_string();
    return 0;
}
