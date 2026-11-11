#include <iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string k;
    while(n--){
        int n;
        string s;
        cin>>n>>s;
        for(int i = 0; i < n; i ++){
            k+=s;
        }
    }
    int cnt = 0;
    for(int i = 0; i < k.length()/2; i++){
		cnt += k[i]!=k[k.length()-i-1];
    }
    cout<<cnt;
}

