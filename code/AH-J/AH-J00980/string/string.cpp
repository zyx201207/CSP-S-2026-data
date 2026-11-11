#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int i;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a[i],&c[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int in=s.size()-1,sum=0;
    for(int i=0;i<in;i++){
        if(s[i]!=s[in]){
            sum++;
        }
        in--;
    }
    cout<<sum;
    return 0;
}
