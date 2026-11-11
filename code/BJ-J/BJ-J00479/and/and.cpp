#include <bits/stdc++.h>
using namespace std;
void xunhuan(long long &m,long long &n,long long &j,vector<int> &numb,int &linshi,int arr,int &cnt,int &maxres){
    for(int i=j;i<n;i++){
        cnt++;
        numb.push_back(arr[i]);
        if(cnt!=m)return xunhuan(m,n,j+1,numb,linshi,arr,cnt,maxres);
        for(int i=1;i<numb.size()-1;i++){
            linshi=numb[0];
            linshi=linshi & numb[i];
        }
        if(maxres<linshi)maxres=linshi;
        numb.pop_back();
        linshi=0;
        cnt--;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long m,n;
    cin>>n>>m;
    int arr[n];
    int maxres=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int j=0;j<n-m;j++){
        linshi=0;
        vector<int> numb;
        int cnt=0;
        return xunhuan(m,n,j,numb,linshi,arr,cnt);
    }
    cout<<maxres<<endl;
