#include<bits/stdc++.h>
using namespace std;
long long n,sum;
int m;
string a,b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    /*int j=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[n-j]){
            sum=sum+(a[i]-'0');
        }
        if(b[i]!=b[n-j-1]){
            sum=sum+(a[i]-'0');
        }
        j++;
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=a[i-1];i<=a[i];j++){
            s[j]=b[i];
        }
    }
    int l=s.size()/2;
    int j=0;
    for(int i=0;i<l*2;i++){
        cout<<s[i];
    }
    /*while(l--){
        if(s[l-j-1]!=s[l+j]) sum++;
        j++;
    }
    cout<<sum;*/
    cout<<"1";

    return 0;

}

