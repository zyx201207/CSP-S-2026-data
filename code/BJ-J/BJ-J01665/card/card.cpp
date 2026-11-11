#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int s[500005];
void init(){
    for(int i=1;i<=n;i++)s[i]=a[i];
}
int cnt[500005]={0};
void xxx(int x){
    vector<int> ve;//桌面
    ve.clear();
    for(int i=x;i<=n;i++){
        if(ve.empty()){
            ve.push_back(a[i]);
        }else{
            for(int j=0;j<ve.size();j++){
                if(ve[j]==a[i]){
                    ve.erase(ve.begin()+j,ve.end());
                    break;
                }
            }
            ve.push_back(a[i]);
        }
    }
    for(auto it:ve){
        cnt[it]++;
    }
}
void xxx2(int x){
    vector<int> ve;//桌面
    ve.clear();
    for(int i=x;i<=n;i++){
        if(ve.empty()){
            ve.push_back(a[i]);
        }else{
            int j=lower_bound(ve.begin(),ve.end(),a[i])-ve.begin();
            if(ve[j]==a[i]){
                ve.erase(ve.begin()+j,ve.end());
            }
            ve.push_back(a[i]);
        }
    }
    for(auto it:ve){
        cnt[it]++;
    }
}
int A=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    A=1;
    for(int i=1;i<n;i++){
        if(a[i]>a[i+1]){
            A=0;
            break;
        }
    }
    if(n<=500){
        for(int i=1;i<=n;i++){
            init();
            xxx(i);
        }
        for(int i=1;i<=m;i++){
            if(i==m){
                cout<<cnt[i];
                break;
            }
            cout<<cnt[i]<<" ";
        }
        cout<<endl;
    }else if(n<=5000 && A){
        for(int i=1;i<=n;i++){
            init();
            xxx2(i);
        }
        for(int i=1;i<=m;i++){
            if(i==m){
                cout<<cnt[i];
                break;
            }
            cout<<cnt[i]<<" ";
        }
        cout<<endl;
    }else if(m==2){
        for(int i=1;i<=m;i++){
            cout<<1<<" ";
        }
        cout<<endl;
    }else{
        for(int i=1;i<=n;i++){
            init();
            xxx(i);
        }
        for(int i=1;i<=m;i++){
            if(i==m){
                cout<<cnt[i];
                break;
            }
            cout<<cnt[i]<<" ";
        }
        cout<<endl;
    }
    //36pts
    return 0;
}
