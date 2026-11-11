#include<iostream>
#include<stack>
#define clientaa
using namespace std;
int lft[300000];
bool contain[300000];
int p[500000];
int main(){
    #ifndef clientaaa
    freopen("cards.in","r",stdin);
    freopen("cards.out","w",stdout);
    #endif
    int n,m;cin>>n>>m;
    stack<int> pai;
    for(int i=0;i<n;i++){
        cin>>p[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;++j){
            if(j<i)continue;
            if(contain[p[j]]){
                while(pai.top()!=p[j]){
                    contain[pai.top()]=0;
                    pai.pop();
                }
            }
            contain[p[j]]=1;
            pai.push(p[j]);
        }
        while(!pai.empty()){
            lft[pai.top()]++;
            pai.pop();
        }
    }
    for(int i=0;i<m;i++){
        cout<<lft[i]<<" ";
    }
    return 0;
}
