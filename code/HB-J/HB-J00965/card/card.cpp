#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> s(n);
    int MAX=-9999;
    for(int i=0;i<n;i++){
        cin>>s[i];
        MAX=max(MAX,s[i]);
    }
    vector<int> a(n,-1);
    for(int p=0;p<n;p++){
        vector<bool> biaoji(n,0);
        vector<int> chupai(n,0);
        for(int i=p;i<n;i++){
            if(!biaoji[s[i]]){
                biaoji[s[i]]=true;
                chupai[i]=s[i];
            }else{
                for(int j=i-1;j>=0;j--){
                    if(chupai[j]==s[i]){
                        chupai[j]=0;
                        break;
                    }else{
                        chupai[j]=0;
                        biaoji[chupai[j]]=false;
                    }
                }
                chupai[i]=s[i];
                biaoji[chupai[i]]=true;
            }
        }
        for(int i=0;i<MAX;i++){
            if(biaoji[s[i]]==true){
                a[s[i]]++;
            }
        }
    }
    for(int i=0;i<MAX;i++){
        if(a[s[i]]!=-1){
            cout<<a[s[i]]+1<<" ";
        }
    }
    return 0;
}
