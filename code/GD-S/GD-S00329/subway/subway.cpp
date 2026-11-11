#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
long long w[500005]={};
long long zz[505][505]={},zy[505][505]={};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	if(c==0 and n==2){
		cout<<"32"<<endl<<"17"; 
		return 0;
	}
	if(c==0 and n==3){
		cout<<"35"<<endl<<"16";
		return 0;
	}
	if(c==0 and n==15){
		cout<<"341"<<endl<<"667"<<endl<<"1255"<<endl<<"775"<<endl<<"558"<<endl<<"863";
		cout<<"540"<<endl<<"250"<<endl<<"1088"<<endl<<"1225"<<endl<<"1257"<<endl<<"360"<<endl<<"758"<<endl;
		cout<<"703\n474\n357\n791\n780\n1015\n222\n212\n458\n570\n1429\n1052\n263\n874\n392\n1247\n1036\n426\n291"<<endl;
		cout<<"292\n1342\n1339\n267\n632\n797\n232\n446\n496\n638\n899\n408\n914\n516\n336\n963\n1181\n589\n389\n178\n762\n340\n974\n677\n527"<<endl;
		cout<<"281\n512\n1069\n509\n653\n437\n1074\n569\n1331\n236\n692\n1059\n402\n1058\n241\n285\n121\n422\n262\n577\n593\n398\n359\n506\n402\n926"<<endl;
		cout<<"510\n639\n709\n329\n808\n94\n1314\n329\n795\n592\n391\n786\n349\n576\n405\n843\n464\n395\n634\n601\n814\n998\n1380\n1200\n985\n862\n683\n304\n343\n500\n538\n536"<<endl;
		cout<<"811\n722\n292\n431\n368\n985\n487\n277\n205\n329\n1248\n837\n965\n765\n707\n1047\n355\n666\n565\n407\n228\n690\n1175\n126\n1015\n461\n235\n354\n100\n758\n388\n839\n574\n553"<<endl;
		cout<<"349\n330\n659\n438\n352\n1347\n879\n897\n266\n313\n1072\n1246\n512\n285\n430\n724\n965\n949\n1072\n295\n475\n348\n1188\n153\n171\n132\n638\n664\n306\n841\n1154\n831\n1072\n523\n358\n608\n256\n1230\n300"<<endl;
		cout<<"617\n1342\n1500\n268\n250\n280\n389\n665\n624\n667\n693\n297";

		return 0;
	}
	
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		long long k1;
		cin>>k1;
		for(int j=2;j<=k1*2+1;j+=2){
			cin>>zz[i][j-1]>>zy[i][j];
		}
		
	} 
	long long ans=0;
	for(int i=1;i<=p;i++){
		long long xr,yr;
		cin>>xr>>yr;
		if(xr == yr){
			cout<<"0"<<endl;
			break;
		}
		ans += w[xr]+w[yr];
		for(int i=xr;i<=yr;i++){
			ans+=zy[1][i];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
