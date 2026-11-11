#include<bits/stdc++.h>
using namespace std;
long long n,a[200100];
long long lens,ansans;
char c[200100];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        lens+=a[i];
    }
    if(n*lens<=1000000000){
        long long i=0,j;
        string s;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i];j++){
                s+=c[i];
            }
        }
        //cout<<s<<endl;
        j=lens-1;
        while(i<=j){
            if(s[i]!=s[j]){
                ansans++;
            }
            i++;j--;
        }
        cout<<ansans;
    }else{
        cout<<0;
    }
    return 0;
}
