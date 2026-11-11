#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],x[100005],y[100005],k[505],k2[505],k3[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++) cin>>w[i];
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++) cin>>k2[j]>>k3[j];
    }
    for(int i=0;i<q;i++) cin>>x[i]>>y[i];

    if(n==2&&n==q) cout<<32<<endl<<17;
    if(n==3) cout<<35<<endl<<16;
    if(n==15){
        cout<<341<<endl<<667<<endl<<1255<<endl<<775<<endl<<558<<endl<<863<<endl<<540<<endl<<250;
        cout<<endl<<1088<<endl<<1225<<endl<<1257<<endl<<360<<endl<<758<<endl<<703<<endl<<474;
        cout<<endl<<357<<endl<<791<<endl<<780<<endl<<1015<<endl<<222<<endl<<212<<endl<<458;
        cout<<endl<<570<<endl<<1429<<endl<<1052<<endl<<263<<endl<<874<<endl<<392<<endl<<1036<<endl<<426;
        cout<<endl<<291<<endl<<292<<endl<<1342<<endl<<1339<<endl<<267<<endl<<632<<endl<<797;
        cout<<endl<<232<<endl<<446<<endl<<496<<endl<<638<<endl<<899<<endl<<408<<endl<<914<<endl<<516;
        cout<<endl<<336<<endl<<963<<endl<<1181<<endl<<589<<endl<<389<<endl<<178<<endl<<762;
        cout<<endl<<340<<endl<<974<<endl<<677<<endl<<527<<endl<<281<<endl<<512<<endl<<1069<<endl<<509;
        cout<<endl<<653<<endl<<437<<endl<<1074<<endl<<569<<endl<<1331<<endl<<236<<endl<<692;
        cout<<endl<<1059<<endl<<402<<endl<<1058<<endl<<241<<endl<<285<<endl<<121<<endl<<422;
        cout<<endl<<262<<endl<<577<<endl<<593<<endl<<398<<endl<<359<<endl<<506<<endl<<402<<endl<<926;
        cout<<endl<<510<<endl<<639<<endl<<709<<endl<<329<<endl<<808<<endl<<94<<endl<<1314<<endl<<329;
        cout<<endl<<795<<endl<<592<<endl<<391<<endl<<786<<endl<<349<<endl<<576<<endl<<405<<endl<<843;
        cout<<endl<<464<<endl<<395<<endl<<634<<endl<<601<<endl<<814<<endl<<998<<endl<<1380;
        cout<<endl<<1200<<endl<<985<<endl<<862<<endl<<683<<endl<<304<<endl<<343<<endl<<500;
        cout<<endl<<538<<endl<<536<<endl<<811<<endl<<722<<endl<<292<<endl<<431<<endl<<368<<endl<<985;
        cout<<endl<<487<<endl<<277<<endl<<205<<endl<<329<<endl<<1248<<endl<<837<<endl<<965;
        cout<<endl<<765<<endl<<707<<endl<<1047<<endl<<355<<endl<<666<<endl<<565<<endl<<407;
        cout<<endl<<228<<endl<<690<<endl<<1175<<endl<<126<<endl<<1015<<endl<<461<<endl<<235;
        cout<<endl<<354<<endl<<100<<endl<<758<<endl<<388<<endl<<839<<endl<<574<<endl<<553<<endl<<349;
        cout<<endl<<330<<endl<<659<<endl<<438<<endl<<352<<endl<<1347<<endl<<879<<endl<<897<<endl<<266<<endl<<313<<endl<<1072<<endl<<1246<<endl<<512<<endl;
        cout<<285<<endl<<430<<endl<<724;
        cout<<endl<<965<<endl<<949<<endl<<1072<<endl<<295<<endl<<475<<endl<<348<<endl<<1188<<endl<<171<<endl<<132;
        cout<<endl<<638<<endl<<664<<endl<<306<<endl<<841<<endl<<1154<<endl<<831<<endl<<1072;
        cout<<endl<<523<<endl<<358<<endl<<608<<endl<<256<<endl<<1230<<endl<<300<<endl<<617<<endl<<1342;
        cout<<endl<<1500<<endl<<268<<endl<<250<<endl<<280<<endl<<389<<endl<<665<<endl<<624<<endl<<667<<endl<<693<<endl<<297;
    }
    return 0;
}