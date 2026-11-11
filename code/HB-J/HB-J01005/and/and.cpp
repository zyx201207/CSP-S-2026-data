#include<bits/stdc++.h>
using namespace std;
bool num[200005][31];
bool book[200005];
int book1[31];
void two(int a,int where){
    int w=0;
    while(a>0){
        if(a%2){
            book1[w]++;
            num[where][w]=1;
        }
        w++;
        a/=2;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("add.out","w",stdout);
    int n,m,ans=0;
    cin >> n >> m;
    int n1=n;
    while(n1--){
        book[n1]=1;
    }
    int n2=n;
    while(n2--){
        int a;
        cin >> a;
        two(a,n2);
    }
    for(int i=30;i>=0;i--){
        if(book1[i]<m){
            continue;
        }
        ans+=pow(2,i);
        for(int j=0;j<n;j++){
            if(!num[j][i]){
                if(book[j]){
                    for(int k=0;k<=30;k++){
                        book1[k]--;
                    }
                }
                book[j]=0;
            }
        }
    }
    cout<<ans;
}
