#include<bits/stdc++.h>
using namespace std;
int n,m,mx=0;
vector<int> a,b;
void q(int i,int deep){
    if(deep>m){
        int ad=b[0];
        for(int j=0;j<m;j++){
            ad=ad&b[j];
            //cout<<b[j]<<' ';
        }
        //cout<<endl;
        mx=max(mx,ad);
        return;
    }
    for(int j=i;j<=n-m+i;j++){//
        b.push_back(a[j]);
        q(j+1,deep+1);
        b.pop_back();
    }
    return;
}
int main(){
    ifstream fi("and.in");
    ofstream fo("and.out");
    fi>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        fi>>x;
        a.push_back(x);
    }
    q(0,1);
    fo<<mx<<endl;
    return 0;
}
