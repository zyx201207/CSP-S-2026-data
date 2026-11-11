include<bits/stdc++.h>
using namespace std;
int a[1001],s=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(m>=1){
        if(a[i]==a[i+1]) s+=2;
        else if(a[i]<a[i+1]){
            a[i]+=1;
            s++;
            m--;
        }
    }
    cout<<s;
    return 0;
}
