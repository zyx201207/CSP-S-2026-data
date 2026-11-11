#include<bits/stdc++.h>
using namespace std;
int n,m,max_ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    max_ans=0;
    int x[n];
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            if(x[i]==x[j]){
                if(x[i]>max_ans){
                    max_ans=x[i];
                }
            }
        }
    }
    cout<<max_ans;
    fclose(stdin);
    fclose(stdout);
}
