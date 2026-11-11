#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int answer[200003];
void play(int j,int a[],int m,int n){
    int start=j-1;
    bool bucket[300004]={0};
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(a[start+i]);
        if(bucket[s.top()]==0){
            bucket[s.top()]=1;
        }
        else{
            int head=s.top();
            s.pop();
            while(s.top()!=head){
                bucket[s.top()]=0;
                s.pop();
            }
        }
    }
    for(int k=1;k<=m;k++){
        if(bucket[k]==1){
            answer[k]++;
        }
    }
}
int a[200003];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        play(j,a,m,n);
    }
    for(int l=1;l<=m;l++){
        cout<<answer[l]<<" ";
    }
    return 0;
}