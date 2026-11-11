#include<bits/stdc++.h>
using namespace std;
long long num[200001],bc[200001]={0};
char str[200001];
int find(long long a){
    int i=1;
    for(;;){
        if(a<=bc[i])
            return i;
        else
            i++;
    }
    return 0;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.ans","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i]>>str[i];
    for(int i=1;i<=n;i++)
        bc[i]=bc[i-1]+num[i];
    long long ans=0;
    for(int i=1;i<=int((bc[n]-0.1)/2);i++)
        if(str[find(i)]!=str[find(bc[n]-i+1)])
            ans++;
    cout<<ans;
    return 0;
}
