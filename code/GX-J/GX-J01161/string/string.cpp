#include<bits//stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string x1;
    int u=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        int m;
        cin>>m>>s;
        for(int j=0;j<m;j++){
            s=m*s[i];
            s=s+s;
            x1=s;
        }
        if(x1[i]==x1[x1.size()]+1-i){
            return 0;
        }
        else{
            x1[i]=x1[x1.size()];
            u++;
        }


    }
    cout<<u;



    return 0;
}
