#include<bits/stdc++.h>
using namespace std;
int n,m,s,ans;
int a[1000010],b[100100];
int an[10010][30];
bool cmp(int a,int b){
    if(a>=b){
        return 1;
    }
    return 0;
}
int main(){
    freopen("and4.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        //cout<<(a[i]&int(pow(2,1)))<<endl;
    }
    s=n;
    sort(a,a+n+1);


    for(int i=30;i>=0;i--){
        int e=0;
        for(int j=n;j>=0;j--){
            //if(i==14&&j>n-10)cout<<a[j]<<' '<<pow(2,i)<<endl;
            if((a[j]&int(ans+pow(2,i)))!=0){
                e++;
            }

        }
        //cout<<i<<" "<<e<<endl;
        if(e>=m){

            s=e;
            ans+=int(pow(2,i));
        }
    }
    cout<<ans;




}
