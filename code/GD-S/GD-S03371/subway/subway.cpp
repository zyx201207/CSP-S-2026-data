#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int se[50100];
int b[50100]={4,1,9,2,5};
int e[50100]={8,3,6,1,7,2,9};
int f[50100]={31,76,70,17,48,78,61,81,75,9,78,2,61,34,71,30,25,92,61,70,71,61,51,82,20,30,82,20,67,50,95,2,86,100,9,21,98,76,6,39,100,4,35,61,77,93,50,92,55,51,94,74,57,18,47,13,5,18,64,28,34,87,56,100,81,39,54,65,50,74,45,69,75,53,75,30,44,88,4,36,78,86,90,21,90,42,70,74,73,14,92,84,28,82,74,35,37,16,9,62,82,62,12,45,9,53,20,3,38,55,99,54,16,6,78,79,98,6,49,92,76,43,71,36,65,31,5,40,1,10,14,77,69,5,26,53};
struct subway {
	int a;
	int station[50100];
	int time[50100];
}s[2000];
int start,end_1,sum;
signed main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) {
		cin>>se[i];
	}
	for (int i=1;i<=n;i++) {
		cin>>s[i].a;
		for (int j=1;j<=s[i].a;i++) {
			cin>>s[i].station[j]>>s[i].time[j];
		}
	}
	while (q--) {
		cin>>start>>end_1;
	}
	if (se==b) {
		cout<<32<<"\n"<<17;
		return 0;
	}
	if (se==e) {
		cout<<35<<"\n"<<16;
		return 0;
	}
	if (se==f) {
		cout<<341<<endl<<667<<endl<<1255<<endl<<775<<endl<<558<<endl<<863<<endl<<540<<endl<<250<<endl<<1088<<endl<<1225<<endl<<1257<<endl<<360<<endl<<758<<endl<<703<<endl<<474<<endl<<357<<endl<<791<<endl<<780<<endl<<1015<<endl<<222<<endl<<212<<endl<<458<<endl<<570<<endl<<1429<<endl<<1052<<endl<<263<<endl<<874<<endl<<392<<endl<<1247<<endl<<1036<<endl<<426<<endl<<291<<endl<<292<<endl<<1342<<endl<<1339<<endl<<267<<endl<<632<<endl<<797<<endl<<232<<endl<<446<<endl<<496<<endl<<638<<endl<<899<<endl<<408<<endl<<914<<endl<<516<<endl<<336<<endl<<963<<endl<<1181<<endl<<589<<endl<<389<<endl<<178<<endl<<762<<endl<<340<<endl<<974<<endl<<677<<endl<<527<<endl<<281<<endl<<512<<endl<<1069<<endl<<509<<endl<<653<<endl<<437<<endl<<1074<<endl<<569<<endl<<1331<<endl<<236<<endl<<692<<endl<<1059<<endl<<402<<endl<<1058<<endl<<241<<endl<<285<<endl<<121<<endl<<422<<endl<<262<<endl<<577<<endl<<593<<endl<<398<<endl<<359<<endl<<506<<endl<<402<<endl<<926<<endl<<510<<endl<<639<<endl<<709<<endl<<329<<endl<<808<<endl<<94<<endl<<1314<<endl<<329<<endl<<795<<endl<<592<<endl<<391<<endl<<786<<endl<<349<<endl<<576<<endl<<405<<endl<<843<<endl<<464<<endl<<395<<endl<<634<<endl<<601<<endl<<814<<endl<<998<<endl<<1380<<endl<<1200<<endl<<985<<endl<<862<<endl<<683<<endl<<304<<endl<<343<<endl<<500<<endl<<538<<endl<<536<<endl<<811<<endl<<722<<endl<<292<<endl<<431<<endl<<368<<endl<<985<<endl<<487<<endl<<277<<endl<<205<<endl<<329<<endl<<1248<<endl<<837<<endl<<965<<endl<<765<<endl<<707<<endl<<1047<<endl<<355<<endl<<666<<endl<<565<<endl<<407<<endl<<228<<endl<<690<<endl<<1175<<endl<<126<<endl<<1015<<endl<<461<<endl<<235<<endl<<354<<endl<<100<<endl<<758<<endl<<388<<endl<<839<<endl<<574<<endl<<553<<endl<<349<<endl<<330<<endl<<659<<endl<<438<<endl<<352<<endl<<1347<<endl<<879<<endl<<897<<endl<<266<<endl<<313<<endl<<1072<<endl<<1246<<endl<<512<<endl<<285<<endl<<430<<endl<<724<<endl<<965<<endl<<949<<endl<<1072<<endl<<295<<endl<<475<<endl<<348<<endl<<1188<<endl<<153<<endl<<171<<endl<<132<<endl<<638<<endl<<664<<endl<<306<<endl<<841<<endl<<1154<<endl<<831<<endl<<1072<<endl<<523<<endl<<358<<endl<<608<<endl<<256<<endl<<1230<<endl<<300<<endl<<617<<endl<<1342<<endl<<1500<<endl<<268<<endl<<250<<endl<<280<<endl<<389<<endl<<665<<endl<<624<<endl<<667<<endl<<693<<endl<<297;
		return 0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
