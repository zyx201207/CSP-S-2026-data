#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r","stdin");
	freopen("card.out","w","stdout");
    int n,m,x[200005]={},y[200005]={};cin>>n>>m;
    string zm;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    x[n+1]=',';
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            zm+=('0'+x[j]);
            zm+=',';
            for(int k=1;k<=n;k++){
                if(zm[k]=='0'+x[j])zm[k+1]=',';
            }
        }
        for(int i=0;i<200005;i++){
            if(zm[i]==',')break;
            y[zm[i]-'0']++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<y[i];
    }
}