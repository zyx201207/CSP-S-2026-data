#include<iostream>
using namespace std;

int g(int*arr,int n,int m,int ma,int su){
    if(su>m||ma>n-2) return 0x7fffffff;
    int res=0;
    int no;
    for(int i=ma+1;i<n;i++){no=g(arr,n,m,i,su+1)&arr[i];res=max(no,res);}
    return res;
}

int f(int*arr,int n,int m){
    return g(arr,n,m,0,0);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    int* arr=new int[n];for(int i=0;i<n;i++)cin>>arr[i];
    cout<<f(arr,n,m);
    delete[] arr;
    return 0;
}
