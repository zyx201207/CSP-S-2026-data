#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    int n , m;
    cin>>n>>m;
    int p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    vector<int> v(m+1 , 0);
    for(int H=0;H<n;H++){
        vector<bool> c(m+1 , false);
        vector<int> w(m+1);
        vector<int> d(n , 0);
        int j=0;
        for(int i=H;i<n;i++){
            if(!c[p[i]]){
                d[j]=p[i];
                c[p[i]]=true;
                w[p[i]]=j;
                j++;
            }else{
                j=w[p[i]];
                for(int y=j;y<n;y++){
                    c[p[y]]=false;
                    d[y]=0;
                }
                d[j]=p[i];
                c[p[i]]=true;
                w[p[i]]=j;
                j++;
            }
        }
        for(int i=0;i<n;i++){
            if(d[i]){
                v[d[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
            cout<<v[i]<<' ';
    }
    cout<<endl;
    return 0;
}
