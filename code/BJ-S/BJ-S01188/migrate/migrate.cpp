#include<bits/stdc++.h>
using namespace std;
int x[100005];
vector<int> sums;
        int n,d;
int dis(int x1,int x2){
    return max(x1,x2)-min(x1,x2);
}
void dfs(int from,int to,int num){
      //  cerr<<"from:"<<from<<" to:"<<to<<" num:" << num<<endl;
    if(from==to){
        sums.push_back(num);
        return;
    }
    for(int i=from;i<=to;i++){

        if((dis(x[from],x[i])<=d)&&i!=from){
            if((from==4)&&(to==5)){
                 //   cerr<<i;
               // cerr<< "ok--debug:dis:" << dis(x[from],x[i]) <<" "<<num<< endl;
            }
            dfs(i,to,num+1);
        }else if(i!=from){
            break;
        }
    }
}
bool cannotdo(int from,int to){
    for(int i=from+1;i<=to;i++){
         //   cerr <<from<<" "<<to<<" " <<x[i]-x[i-1]<<endl;
        if((x[i]-x[i-1])>d){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;

    while(t--){
            int bencisum=0;
        cin >> n >> d;
        sums.resize(100005);

for(int i=1;i<=n;i++){
            cin >> x[i];
        }
        for(int i=1;i<=n;i++){
            for(int len=4;len<=n-i+1;len++){
                    if(cannotdo(i,i+len-1)){
                        continue;
                    }
                        dfs(i,i+len-1,0);
        int howmany=0,minen=INT_MAX;
        for(int the:sums){
                if(the==0){
                    continue;
                }
            //cerr << i << " " << i+len-1 <<" "<< the << endl;
            if(the==minen){
                howmany++;
            }
            if(the<minen){
                howmany=1;
                minen=the;
            }
        }
       // cerr << i << " " << i+len-1 <<" "<<howmany<<" min:"<<minen<< endl;
        if(howmany==2){
            bencisum++;
        }
            }
        }
        cout << bencisum<<endl;
    }
    return 0;
}
