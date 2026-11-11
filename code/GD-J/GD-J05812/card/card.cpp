#include<iostream>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    int k,rig;
    int* cards=new int[m];          //点数对应牌的位置（在桌面上）
    int* table=new int[n];          //桌面上对应位置的牌
    int* start=new int[n];
    int* res=new int[m]();
    for(int i=0;i<n;i++) cin>>start[i];
    for(int i=0;i<n;i++) cout<<start[i]<<endl;
    for(int i=0;i<n;i++){
        rig=0;
        for(int j=0;j<m;j++) cards[j]=-1;
        for(int j=0;j<n;j++) table[j]=-1;
        for(int j=i;j<n;j++){
            k=start[j];
            if(cards[k]+1)while(rig>cards[k])if(table[rig]+1){
                cards[table[rig]]=-1;
                table[rig--]=-1;
            }
            table[rig]=k;
            cards[k]=rig++;
        }
        for(int j=0;j<m;j++)if(cards[j]+1)res[j]++;
        for(int j=0;j<m;j++)cout<<cards[j]<<' ';
        cout<<endl;
        for(int j=0;j<m;j++)cout<<table[j]<<' ';
        cout<<endl;
    }
    for(int i=0;i<m;i++)cout<<res[i]<<' ';
    delete[] cards;
    delete[] table;
    delete[] start;
    delete[] res;
    return 0;
}
