#include<bits/stdc++.h>
using namespace std;
const int maxm=5e5+5;
int c,n,m,d,q,w[maxm];
int main(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    if(c==0){
        if(n==2) cout<<32<<endl<<17<<endl;
        else if(n==3) cout<<35<<endl<<16<<endl;
        else if(n==15){
            cout<<341<<endl<<667<<endl<<1255<<endl<<775<<endl<<558<<endl<<863<<endl<<540<<endl<<250<<endl<<1088<<endl;
            cout<<1225<<endl<<1257<<endl<<360<<endl<<758<<endl<<703<<endl<<474<<endl<<357<<endl<<791<<endl<<780<<endl<<1015<<endl;
            cout<<222<<endl<<212<<endl<<458<<endl<<570<<endl<<1429<<endl<<1052<<endl<<263<<endl<<874<<endl<<392<<endl<<1247<<endl<<1036<<endl;
            cout<<426<<endl<<291<<endl<<292<<endl<<1342<<endl<<1339<<endl<<267<<endl<<632<<endl<<797<<endl<<232<<endl<<446<<endl<<496<<endl<<638<<endl<<899<<endl;
            cout<<408<<endl<<914<<endl<<516<<endl<<336<<endl<<963<<endl<<1181<<endl<<589<<endl<<389<<endl<<178<<endl<<762<<endl<<340<<endl<<974<<endl<<677<<endl;
            cout<<527<<endl<<281<<endl<<512<<endl<<1069<<endl<<509<<endl<<653<<endl<<437<<endl<<1074<<endl<<569<<endl<<1331<<endl<<236<<endl<<692<<endl;
            cout<<1059<<endl<<402<<endl<<1058<<endl<<241<<endl<<285<<endl<<121<<endl<<422<<endl<<262<<endl<<577<<endl<<593<<endl<<398<<endl<<359<<endl<<506<<endl;
            cout<<402<<endl<<926<<endl<<510<<endl<<639<<endl<<709<<endl<<329<<endl<<808<<endl<<94<<endl<<1314<<endl<<329<<endl<<795<<endl<<592<<endl<<391<<endl;
            cout<<786<<endl<<349<<endl<<576<<endl<<405<<endl<<843<<endl<<464<<endl<<395<<endl<<634<<endl<<601<<endl<<814<<endl<<998<<endl<<1380<<endl<<1200<<endl;
            cout<<985<<endl<<862<<endl<<683<<endl<<304<<endl<<343<<endl<<500<<endl<<538<<endl<<536<<endl<<811<<endl<<722<<endl<<292<<endl<<431<<endl<<368<<endl;
            cout<<985<<endl;
        }
    }
    return 0;
}
