#include<bits/stdc++.h>
using namespace std;
int main() {
freopen ("card.in","r",stdin);
freopen ("card.out","w",stdout);
    int paishu;
    cin>>paishu;
    int zhongshu;
    cin>>zhongshu;
    int pai[paishu];
    int wan [paishu+100];
    int sum[zhongshu];
    int xianyou=0;
    for (int i=0;i<paishu;i++) {
    cin>>pai[i];
    } 
    for (int i=paishu;i>0;i--) {
    xianyou=0;
        for (int j=0;j<i;i++) {
             wan[xianyou]=pai[i+j];
             for (int ii=0;ii<xianyou;ii++) {
                 if(wan[xianyou]==wan[i]) {
                    for(int iii=i;i<=xianyou;i++) {
                        wan[iii]=0;
                        xianyou--;
                        wan[xianyou]=pai[i+j];
                    }
                 }
                xianyou++; 
             }
        }
        for(int x=0;x<paishu+100;x++) {
			wan[x]=0;
			}
        for(int iiii=1;i<=xianyou;i++){
            sum[wan[iiii]]++;
        }
    }
    for(int iiiii=1;iiiii<zhongshu;iiiii++) {
        cout<<sum[iiiii];
    }
    return 0;
}
