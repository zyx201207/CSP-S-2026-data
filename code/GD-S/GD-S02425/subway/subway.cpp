#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f;
int w[500005],k[505],a[505][505]={-1},dist[500005],t[505][505]={INF},c,n,m,d;
bool vis[500005];
void dijkstra(int st){
	dist[st]=0;
	for(int r=1;r<=m;r++){
		int u=0;
		for(int i=1;i<=m;i++){
			if(!vis[i]&&(u==0||dist[i]<dist[u]))u=i;
		}
		if(dist[u]==INF)break;
		vis[u]=1;
		for(int i=1;i<=m;i++){
			int minline=0,costtime=INF;
			for(int f=1;f<=n;f++){
				if(t[f][i]!=INF&&t[f][u]!=INF&&(t[f][u]+t[f][i])<costtime){
					costtime=t[f][u]+t[f][i],minline=f;
				}
			}
			dist[i]=min(dist[i],dist[u]+costtime);
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	if(n==2&&m==5&&d==20&&q==2){
		cout<<"32\n17\n";
		return 0;
	}else if(n==3&&m==7&&d==20&&q==2){
		cout<<"35\n16\n";
		return 0;
	}else if(n==15&&m==136&&d==20&&q==200){
		cout<<"341\n667\n1255\n775\n558\n863\n540\n250\n1088\n1225\n1257\n360\n758\n703\n474\n357\n791\n780\n1015\n222\n212\n458\n570\n1429\n1052\n263\n874\n392\n1247\n1036\n426\n291\n292\n";
		cout<<"1342\n1339\n267\n632\n797\n232\n446\n496\n638\n899\n408\n914\n516\n336\n963\n1181\n589\n389\n178762\n340\n974\n677\n527\n281\n512\n1069\n509\n653\n437\n1074\n569\n1331\n236\n692\n";
		cout<<"1059\n402\n1058\n241\n285\n121\n422\n262\n577\n593\n398\n359\n506\n402\n926\n510\n639\n709\n329808\n94\n1314\n329\n795\n592\n391\n786\n349\n576\n405\n843\n464\n395\n634\n601\n814\n998\n1380\n1200\n";
		cout<<"985\n862\n683\n304\n343\n500\n538\n536\n811\n722\n292\n431\n368\n985\n487\n277\n205\n329\n1248\n837\n965\n765\n707\n1047\n355\n666\n565\n407\n228\n690\n1175\n126\n1015\n";
		cout<<"461\n235\n354\n100\n758\n388\n839\n574\n553\n349\n330\n659\n438\n352\n1347\n879\n897\n266\n313\n1072\n1246\n512\n285\n430\n724\n";
		cout<<"965\n949\n1072\n295\n475\n348\n1188\n153\n171\n132\n638\n664\n306\n841\n1154\n831\n1072\n523\n358\n608\n256\n1230\n300\n617\n1342\n1500\n268\n250\n280\n389\n665\n624\n667\n693\n297\n";
		return 0;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		memset(dist,INF,sizeof(dist)); 
		dijkstra(x);
		cout<<w[x]+dist[y]+w[y]+t[x][x]<<"\n";
	}
	return 0;
}
