#include<iostream>
#include<stack>
#include<fstream>
using namespace std;
const int MAXN=5e5+5;
const int MAXM=3e5+5;
int n,m;
int a[MAXN],ans[MAXM];
int main(){
    freopen("card6.in","r",stdin);
    freopen("card6.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        bool have[MAXM]={};
        stack<int> s;
        for(int j=i;j<=n;j++){
            if(have[a[j]]){
                while(!s.empty()){
                    if(s.top()==a[j]){
                        break;
                    }else{
                        //cout<<0;
                        have[s.top()]=false;
                        s.pop();
                    }
                }
            }else{
                s.push(a[j]);
                have[a[j]]=true;
            }
        }
        while(!s.empty()){
            ans[s.top()]++;
            //cout<<s.top()<<" ";
            s.pop();
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
