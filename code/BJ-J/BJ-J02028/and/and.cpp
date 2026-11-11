#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],ansans;
string s[200100];
bool bj[200100];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }int maxx=-1;
    for(int i=1;i<=n;i++){
        int totot=0;
        while(a[i]>0){
            s[i]=s[i]+char((a[i]%2)+'0');
            a[i]/=2;
            totot++;
        }
        maxx=max(maxx,totot);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<maxx;j++){
            if(s[i][j]!='1'){
                s[i][j]='0';
            }
            //cout<<s[i][j];
        }
        //cout<<endl;
    }
    int cntcnt=0;
    for(int j=maxx-1;j>=0;j--){
        for(int i=1;i<=n;i++){
            if(bj[i]){
                continue;
            }
            if(s[i][j]=='1'){
                cntcnt++;
            }
        }
        if(cntcnt>=m){
            for(int i=1;i<=n;i++){
                if(s[i][j]!='1'&&!bj[i]){
                    bj[i]=1;
                }
            }
            ansans+=pow(2,j);
        }
        cntcnt=0;
    }
    cout<<ansans;
    return 0;
}
