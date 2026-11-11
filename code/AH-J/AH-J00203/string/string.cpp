#include<bits/stdc++.h>
using namespace std;
long long n,t[200005];
unsigned long long cnt;
map<char,long long>m;
char c[200005];
bool flag;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>c[i];
        m[c[i]]+=t[i];
        if(m[c[i]]==t[i])cnt++;
    }
    if(cnt==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n/2+1;i++){
        if(t[i]!=t[n-i+1]||c[i]!=c[n-i+1]){
            flag=1;
            break;
        }
    }
    if(!flag){
        cout<<0;
        return 0;
    }
    cnt=0;
    for(int i=1;i<=n/2+1;i++){
        if(n-i+1==i)break;
        if(c[i]!=c[n-i+1]){
            cnt+=t[i];
            if(t[n-i+1]>=t[i]){
                t[n-i+1]-=t[i];
                t[i+1]-=t[n-i+1];
            }else{
                t[n-i]-=t[i]-t[n-i+1];
                t[n-i+1]-=t[i];
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
