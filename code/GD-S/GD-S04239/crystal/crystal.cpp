#include<bits/stdc++.h>
using namespace std;

long long n,m,tmp,tmp1,res,mxx=0,di,maxx;
double cnt,cnt2;
vector<long long> pg;
vector<long long> mg;
bool dc=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.ans","w",stdout);
    cin>>n>>m;
    mg.resize(0x3f3f);
    cin>>tmp;
    pg.push_back(tmp);
    mg[0]++;
    di=0-tmp;
    cin>>tmp;
    pg.push_back(tmp);
    mg[di+tmp]++;
    cnt=pg[1]-pg[0];
    for(long long i=2;i<n;i++){
        cin>>tmp;
        pg.push_back(tmp);
        mg[di+tmp]++;
        cnt2=pg[i]-pg[i-1];
        if(cnt2!=cnt)  dc=0; 
    }
    if(dc){
        res=sqrt((2*m)/cnt+0.25)-0.5;
        cout<<res;
    }else{
        for(int i=0;i<n;i++){
            if(mg[i]>=mg[mxx]){
                mxx=i;
            }
        }
        for(int i=mxx-1;i>=0;){
            if(mg[i]==0){
                i--;
                continue;
            }
            if(mxx-i>m){
                cout<<res<<"\n";
                return 0;
            }
            res++;
            mg[i]--;
            m--;
        }
    }
}