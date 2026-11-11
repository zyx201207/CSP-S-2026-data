#include <bits/stdc++.h>
using namespace std;
vector<char>v;
vector<char>v2;
vector<char>a;
int n;
int answer=1e4+5;
void BFS(int index,int cnt){
int ans=0;
    for(int i=0;i<v2.size();i++){
        for(int j=v2.size();j>=0;j--){
            if(v2[i]==v2[j])ans++;
        }
    }
    if(ans==v2.size()){
        if(cnt<answer){answer=cnt;return;}
             
    }
    for(int i=0;i<a.size();i++){
    if(v[index]!=a[i]){
        v2[index]=a[i];
        BFS(index+1,cnt+1);
        v2[index]=v[index];
        }
    }
    BFS(index+1,cnt);

}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;a.push_back(y);
        for(int j=1;j<=x;j++){v.push_back(y);v2.push_back(y);}
    }
    BFS(0,0);
    cout<<answer;
    return 0;
}