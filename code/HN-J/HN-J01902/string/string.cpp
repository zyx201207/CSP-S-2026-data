includes<bits/stdc++.h>;
using namespace std;


int main(){
    int n,s,t;
    long long  a[]={};
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n;i++){
        cin >>t>>s;
        for(int j=0;j<=s;j++){
            a[i]=t;
        }

    }
    for(int i=0;i<=a.size/2;i++){
        if(a{i}==a{a.size-i}){
            cout <<a;
        }
    }
    return 0;
}
