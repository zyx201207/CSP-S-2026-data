#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>v;
    for(int i=0;i<n;i++){
    	memset(c,0,sizeof(c));
        for(int j=i;j<n;j++){
            if(c[a[j]]){
                while(v.size()&&v.back()!=a[j]){
                    c[v.back()]--;v.pop_back();
                }
                if(v.size()){
                    c[v.back()]--,v.pop_back();
                }
            }
            v.push_back(a[j]),c[a[j]]++;
            //for(int i=0;i<v.size();i++)cout<<v[i]<<' ';//
            //cout<<'\n';
        }
        //cout<<"---------";//
        for(int j=0;j<v.size();j++)
        	b[v[j]]++;
        while(v.size()){
            //cout<<v.back()<<' ';
            v.pop_back();
        }
        //for(int j=1;j<=m;j++)cout<<b[j]<<' ';//
        //cout<<'\n';
    }
    for(int i=1;i<=m;i++)
            cout<<b[i]<<' ';
    return 0;
}
