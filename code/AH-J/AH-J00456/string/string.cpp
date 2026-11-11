#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long totals,total,crt;
char c[200005];

void isdft(int x,int y){
        if(c[x]==c[y]){
                return ;
        }
        if(a[x]>=a[y]){
                crt+=a[y];
        }
        else{
                crt+=a[x];
        }

}

int main(){
        freopen("string.in","r",stdin);
        freopen("string.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++){
                cin>>a[i]>>c[i];
                if(c[i]==c[i-1]){
                        totals+=a[i];
                }
                total+=a[i];
        }
        if(totals==total){
                cout<<"0"<<endl;
                return 0;
        }
        for(int i=1;i<=n/2;i++){
                isdft(i,n-i+1);
        }
        cout<<crt<<endl;
        return 0;
}

