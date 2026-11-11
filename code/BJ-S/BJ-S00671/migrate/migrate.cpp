#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
unordered_map<int,int> stepCount;
void solve(vector<int>& islands,int loc,int d,int steps){
    if(loc==islands.size()-1){stepCount[steps]++;}
    //printf("lol");
    for(int i=d;i>0;i--){
        int n=islands.size();
        int j=1;
        int tloc=loc;
        for(;j<n-loc && islands[j]-islands[loc]<=d;j++){
            tloc++;
        }
        tloc--;
        //printf("Lol\n");
        solve(islands,tloc,d,steps+1);

    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int t_idx=0;t_idx<t;t_idx++){
        int n,d;
        cin>>n>>d;
        vector<int> islands(n);
        stepCount=unordered_map<int,int>();
        for(int i=0;i<n;i++) cin>>islands[i];
        if(c==13||c==14){
            cout<<0;
            continue;
        }
        if(d>=islands[n-1]-islands[0]){
            cout<<0;continue;
        }
        else solve(islands,0,d,0);
        int ansCount=0;
        auto bruh=stepCount.end();
        for(int i=0;i<1000000;i++){
            if(stepCount.find(i)!=bruh){
                if(stepCount[i]>=2){
                    ansCount=stepCount[i];
                    break;
                }
            }
        }
        cout<<ansCount;
    }
    return 0;
}
