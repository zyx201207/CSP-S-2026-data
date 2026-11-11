#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool great[34];
long long pown(int m){
    long long ret=1;
    for(int i=0;i<m;i++) ret*=2;

    return ret;
}
int sa[200005][34];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        great[i]=true;
        long long p=a[i];
        for(int j=32;j>=0;j--){
            long long q=pown(j);
            if(p>=q && p>0){
                sa[i][j]=1;
                p-=q;
            }else{
                sa[i][j]=0;
            }
        }
    }


    for(int i=32;i>=0;i--){
        int num=0;
        for(int j=0;j<n;j++){

            if(sa[j][i]==1 && great[j]){
                num++;

            }
        }
        if(num>=m){
            for(int j=0;j<n;j++){
                if(sa[j][i]!=1 || great[j]!=true){
                    great[j]=false;
                }
            }
        }
    }
    long long sum=pown(33)-1;
    int nm=m;
    for(int i=0;i<n;i++){
        if(great[i] && m>0){
            sum=sum&a[i];
            m--;
        }
    }
    cout<<sum;
    return 0;
}
