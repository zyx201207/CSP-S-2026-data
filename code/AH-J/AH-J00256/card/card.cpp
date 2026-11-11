#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a[200005];
int ans[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        string s="";
        for(int j=i;j<=n;j++){
            s+=a[j]+'0';
        }
        //cout<<s<<endl;
        for(int j=1;j<=n;j++){
            if(!s.empty()&&s.find(a[i]+'0')>=0&&s.find(a[i]+'0')<s.size()){
                //cout<<s<<' '<<j<<endl;
                s.erase(s.find(a[i]+'0'));
                s+=a[i]+'0';
                //cout<<s<<endl;
            }else{
                s+=a[i]+'0';
            }
        }
        for(char j:s){
            ans[j-'0']++;
        }
    }
    for(int i:ans){
        if(i!=0){
            cout<<i<<' ';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
