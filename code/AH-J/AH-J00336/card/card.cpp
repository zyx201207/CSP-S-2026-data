#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        string s="";
        for(int j=i;j<=n;j++){
            if(s==""){
                s+=(a[j]+48);
            }else{
                int len=s.find(a[j]+48);
                if(len!=-1){
                    s.erase(len+1,s.size()-1-len);
                }else{
                    s+=(a[j]+48);
                }
            }
        }
        if(s!=""){
            for(int i=0;i<s.size();i++){
                b[s[i]-'0']++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
