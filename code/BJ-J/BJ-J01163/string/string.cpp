#include<bits/stdc++.h>
//#define fin cin
//#define fout cout
#define ll long long
using namespace std;
ll p[200005],i,j,n,ans,s;
char q[200005];
int main(){
    ifstream fin;
    ofstream fout;
    fin.open("string.in");
    fout.open("string.out");
    fin>>n;
    for(int k=1;k<=n;k++) fin>>p[k]>>q[k];
    i=1;j=n;ans=0;
    while(i<j){
        s=min(p[i],p[j]);
        p[i]-=s;
        p[j]-=s;
        if(q[i]!=q[j]) ans+=s;
        if(p[i]==0) i++;
        if(p[j]==0) j--;

    }fout<<ans;
    fin.close();
    fout.close();
    return 0;
}
