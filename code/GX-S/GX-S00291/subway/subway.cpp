#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500000];
int mapp[500][500000];
// int k[500];
bool block[500000];
long long timee;
void dfs(int r,int s,int total,int nowroad){
    if(total >= timee)return;
    if(r == s){
        total += mapp[nowroad][r];
        // cout << total << endl;
        if(total < timee)timee = total;
        return;
    }
    block[r] = 1;
    for(int i = 0;i<n;i++){
        if(mapp[i][r] != -1){//station on the road,i is road,r is station
            //change your road?decide you to pay for up and down
            int upp = 0,downn = 0;
            if(nowroad != i && nowroad != -1) upp = mapp[nowroad][r];
            if(nowroad != i) downn = mapp[i][r];
            for(int j = 0;j<m;j++){
                if(mapp[i][j] != -1 && block[j] == 0)dfs(j,s,total+upp+downn,i);
            }
        }
    }
    block[r] = 0;
}
int main(){
    fstream input,output;
    input.open("subway.in",ios_base::in);
    output.open("subway.out",ios_base::out);
    input >> c >> n >> m >> d >> q;
    for(int i = 0;i<m;i++){
        input >> w[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            mapp[i][j] = -1;
        }
    }
    for(int i = 0;i<n;i++){
        int k;
        input >> k;
        for(int j = 0;j<k;j++){
            int a,b;
            input >> a >> b;
            mapp[i][a] = b;
        }
    }
    for(int i = 0;i<q;i++){
        int startt,endd,tmp666;
        timee = 99999999999999999;
        for(int j = 0;j<m;j++){
            block[j] = 0;
        }
        input >> startt >> endd;
        for(int i = 0;i<n;i++){
            if(mapp[i][startt] != -1){//station on the road,i is road,r is station
                tmp666 = i;
                break;
            }
        }
        dfs(startt,endd,0,-1);
        output << timee+w[startt-1]+ w[endd-1] << endl;
    }
    return 0;
}