#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,      m,      d,    n,       q;
//bianhao  xian  zhan   zuiduo     wenti
int inout_pay[2010];
struct Lid{
	int fr;
	int en;
	int v;
};
int mp[1010][1010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>d>>n>>q;
	for(int i=0;i<=1005;i++){
		for(int j=0;j<=1005;j++){
			mp[i][j]=100000000000000;
		}
	}
	//if(c>=7&&c<=11){
		for(int i=1;i<=d;i++){
			cin>>inout_pay[i];
		}
		for(int i=1;i<=m;i++){
			int atmp;cin>>atmp;
			int ap,bp,ic,jc;
			cin>>ap>>ic>>bp>>jc;
			mp[ap][bp]=ic+jc;
			mp[bp][ap]=ic+jc;
		}
		for(int i=1;i<d;i++){
			for(int j=1;j<d;j++){
				if(i==j) continue;
				for(int kt=1;kt<d;kt++){
					mp[i][j]=min(mp[i][j],mp[i][kt]+mp[kt][i]);
				}
			}
		}
		while(q--){
			int qa,qb;
			cin>>qa>>qb;
			cout<<mp[qa][qb]+inout_pay[qa]+inout_pay[qb];
		}
	//}
	return 0;
}
//fan yi yi xia xie xie!

//xie dian shen me hao ne?ben lai wu hua ke shuo.
//zi cong yin wei WHK er ting diao OI zhi hou,zuo ti liang he shu lian du bian zhi xian xia hua.
//zhi xi wang neng hun ge 1= (chu si  de sheng li).
//ke xiao de shi,yi ge xiao you ming qi de zhong xue lian yi ge xiang yang de zhi dao jiao shi dou mei you,xiao dui geng shi yao bu ke ji.
//OIERDB shang li shi di er lian NOIP dou mei qu guo ,geng bu bi shuo wo zhe ge pai bu shang shu de ren le.
//wo you neng zen me ban ne?
//wei yi de gu li shi xue zhang 6&3 bei NOIPlus chuang fei hou,zhong kao yong duo quan xiao di yi.
//ei. wo gai zai na li ting liu? wo wen wo zo ji.
//zui hou zai shuo yi ju mi yu:
//                      takatori jia owas huozfu!
