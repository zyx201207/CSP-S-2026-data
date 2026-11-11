#include<bits/stdc++.h> 
using namespace std;
int mn[500010];
struct{
	int a;
	int t;
}npp[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.ont","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>mn[i];//Ìü 
	}
	for(int i=1;i<=n;i++){
		int j;
		cin>>j;
		for(int x=1;x<=j;x++){
			cin>>npp[i].a>>npp[i].t;
		}//Ì¨ 
	}
	int ans=0;
	while(q--){
		int qi,zo;
		cin>>qi>>zo;
		int zi;
		int ji;
		for(int i=1;i<=n;i++){
			if(npp[i].a==zo){
				ji=i;
			}
			if(npp[i].a==qi){
				zi=i;
			}
		}
		if(qi+1==zo&&zi==ji){
			cout<<mn[qi]+npp[zi].t+mn[zo]+npp[zi].t<<endl;
			break;
		}else if(qi==zo){
			cout<<0<<endl;
			break;
		}else{
			for(int i=qi;i<=zo;i++){
				if(zi==ji&&qi<=zo){
					ans+=mn[qi]+npp[zi].t;
					qi++;
				}else if(zi<ji){//»» 
					ans+=mn[qi+1]+npp[zi+1].t;
					zi++;
					qi++;
				}else if(zi>ji){//»» 
					ans+=mn[qi+1]+npp[zi-1].t;
					zi--;
					qi++;
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
