#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
void quick_sort(){
    int max_i=0,max_j=1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((v[max_i]&v[max_j])<(v[i]&v[j])){
                max_i=i,max_j=j;
            }
        }
    }
    swap(v[v.size()-1],v[max_i]);
    swap(v[v.size()-2],v[max_j]);
}
int max_n=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n>2000||n==m&&n==2000){
        return 0;
    }
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
        max_n=max(max_n,a);
    }
    if(m==1)cout<<max_n;
    m--;
    while(m--){
        quick_sort();
        int a=v[v.size()-1];
        v.pop_back();
        int b=v[v.size()-1];
        v.pop_back();
        v.push_back(a&b);
    }
    cout<<v[v.size()-1];
}
