#include<bits/stdc++.h>
//#define fin cin
//#define fout cout
#define ll long long
using namespace std;
ll p[500005],n,m;
int main(){
    ifstream fin; ofstream fout;
    fin.open("crystal.in");
    fout.open("crystal.out");
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        fin>>p[i];
    }sort(p+1,p+n+1);
    ll j=n,ans=0,cost=0;
    for(int i=n;i>=1;i--){

        while(cost+p[j]-p[i]>m){
            cost-=(j-i)*(p[j]-p[j-1]);
            j--;
        }cost+=p[j]-p[i];ans=max(ans,j-i+1);
    }fout<<ans;
    fin.close();fout.close();
    return 0;
}