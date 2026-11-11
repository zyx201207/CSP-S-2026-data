#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        cin>>c[i-1];
    }
    string s2 = "",s3 = "";
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= a[i];j++){
            s2 += c[i-1];
        }
    }
    for(int i = int(s2.size()-1);i>=0;i-- ){
        s3 += s2[i];
    }
    int cnt = 0;
    for(int i = 0;i < s2.size();i++){
        if(s2[i] != s3[i]){
            cnt++;
            s2[i] = s3[i];
        }
        int m = 0;
        for(int i = int(s2.size()-1);i>=0;i-- ){
            s3[m] = s2[i];
            m++;
        }
        if(s2 == s3){
            cout<<cnt;
            return 0;
        }
    }
    cout<<cnt;
    return 0;
}
