#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[114514];

bool used[114514];
int bc[114514];
int run(int idx){
    int r=0;
    if(idx==m){
        r=a[bc[0]];
        for(int i=1;i<m;i++){
            //cout<<bc[i]<<" ";
            r&=a[bc[i]];
        }//cout<<endl;
        //cout<<r<<endl;
    }
    else for(int i=bc[idx-1];i<n;i++){
        if(used[i])continue;
        bc[idx]=i;
        used[i]=1;
        r=max(r,run(idx+1));
        used[i]=0;
    }
    return r;
}

int main(){
    fstream fi,fo;
    fi.open("and.in");fo.open("and.out");
    fi>>n>>m;
    //cout<<n<<" "<<m<<endl;
    for(int i=0;i<n;i++)fi>>a[i];
    fo<<run(0);
    return 0;
}
