#include<bits/stdc++.h>
using namespace std;
int ans[50005],n,m;
int a[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int>p;
        bool t[50005];
        for(int j=0;j<=m;j++){
            t[j]=false;
        }
        for(int j=i;j<=n;j++){
            if(t[a[j]]==false){
                t[a[j]]=true;
                p.push(a[j]);
            }
            else{
                while(p.size()){
                    int c=p.top();
                    p.pop();
                    if(c==a[j]){
                        break;
                    }
                }
                p.push(a[j]);
            }
        }
        while(p.size()){
            ans[p.top()]+=1;
            p.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout <<ans[i]<<" ";
    }
	return 0;
}
