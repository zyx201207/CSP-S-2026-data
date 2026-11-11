#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int a,p=1,cnt=0,m[100001]={0};
    char n[100001]={0};
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>m[i];
        cin>>n[i];
    }
    int q=a;
    while(p<q){
        if(n[p]!=n[q]){
            cnt+=min(m[p],m[q]);
        }
        if(m[p]<=m[q]){
            m[q]-=m[p];
            m[p]=0;
        }
        if(m[p]>=m[q]){
            m[p]-=m[q];
            m[q]=0;
        }
        if(m[p]<=m[q]){
            p++;
        }
        if(m[p]>=m[q]){
            q--;
        }        
    }
    cout<<cnt;
    return 0;
}
