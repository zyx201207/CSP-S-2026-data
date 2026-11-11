#include<bits/stdc++.h>
//#define fin cin
//#define fout cout
#define ll long long
using namespace std;
int p[500005],ans[500005],n,m;
stack<int> s={};
int vis[500005];
int main(){
   ifstream fin;
   ofstream fout;
   fin.open("card.in");
   fout.open("card.out");
   fin>>n>>m;
   for(int i=1;i<=n;i++){
        cin>>p[i];
   }
   for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int k=p[j];
            if(vis[k]==i){
                while(!s.empty()&&s.top()!=k){
                    vis[s.top()]=0;
                    s.pop();
                }
            }else{
                s.push(k);
                vis[k]=i;
            }
        }while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
   }
   for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
   fin.close();
   fout.close();
    return 0;
}
