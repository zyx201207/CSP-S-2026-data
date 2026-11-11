#include<bits/stdc++.h>
using namespace std;
int n,a[10086],num,ans;
char c[10086];
string str;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            str[num+j]=c[i];
        }
        num+=a[i];
    }
    int R,L;
    if(str.size()%2==0){
        L=str.size()/2;
        R=str.size()/2+1;
    }else{
        L=str.size()/2+1;
        R=L;
    }
    while(R<=str.size()&&L>=0){
        if(R!=L){
            ans++;
        }
        R++;
        L--;
    }
    cout<<ans;
    return 0;
}
