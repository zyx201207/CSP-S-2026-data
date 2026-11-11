#include<bits/stdc++.h>
using namespace std;
int n,a[200009];
char s[200009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    int l=1,w=n;
    long long sum=0;
    while(l!=w){
        if(a[l]>a[w]){
            if(s[l]!=s[w]){
                sum+=a[w];
            }
            a[l]-=a[w];
            w--;
        }else{
            if(s[l]!=s[w]){
                sum+=a[l];
            }
            a[w]-=a[l];
            l++;
        }
    }
    cout<<sum;
    return 0;
}
