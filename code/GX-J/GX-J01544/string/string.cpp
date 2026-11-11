#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int a[200000];
    char c[200000];
    string s1,s2;
    int res = 0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    if(n==1){
        cout<<"0"<<endl;
    }
    else if(n==2 && c[0]==c[1]){
        cout<<"0"<<endl;
    }
    else{
        for(int i=0;i<n;i++){
            s1 += (char)a[i]+c[i];
        }
        for(int i=n-1;i>=0;i--){
            s2 += (char)a[i]+c[i];
        }
        for(int i=0;i<=sizeof(s1)/2-1;i++){
            if(s1[i]!=s2[i] && (char)s1[i]>='a'&&(char)s1[i]<='z' && (char)s2[i]>='a'&&(char)s2[i]<='z') res++;
        }
        cout<<res<<endl;
    }

    return 0;
}
