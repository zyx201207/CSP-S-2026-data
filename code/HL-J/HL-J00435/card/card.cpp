#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        string s="";
        int op=i;
        for(int j=i+1;j<=n;j++){
            string s1=to_string(j);
            if(s.find(s1)==string::npos) s+=s1+" ";
            else{
                int p=s.find(s1);
                s="";
                for(int k=op;k<=p-s1.size();k++){
                    s+=to_string(k)+" ";
                }
                op=p+1;
            }
        }
        for(int j=1;j<=m;j++){
            string sss=to_string(j);
            if(s.find(sss)) ans[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
