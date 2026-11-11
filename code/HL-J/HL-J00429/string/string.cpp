#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
   int n,cnt=0;
    cin>>n;
    string str=" ";
    string s=" ";
    int ai,ci;
    for(int i=1;i<=n;i++){
    	cin>>ai>>ci;
    	for(int j=1;j<=n;j++){
        s+=ci;
}
    }
        for(int i=n;i>=1;i--){
        	str+=ci;
            if(s[i]==str[i]){
                cout<<0;
                return 0;
            }
            else{
                cnt++;
            }
    }
    cout<<cnt;
    retrun 0;
}
