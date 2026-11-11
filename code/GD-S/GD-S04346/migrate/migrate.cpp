//migrate
#include<bits/stdc++.h>
using namespace std;
bool ans[2000005][2000005];
int inde2loca[2000005];
int indchain[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	for(int q=0;q<t;q++){
		for(int i=0;i<2000005;i++){for(int j=0;j<2000005;j++){ans[i][j]=false;}inde2loca[i]=0;indchain[i]=0;}
		int n,d;
		cin >> n >> d;
		for(int i=0;i<n;i++){
			cin >> inde2loca[i];
		}
		for(int l=0;l<n;l++){for(int r=l;r<n;r++){
			int nlo=l,jumps=0;
			int nin=0;
			while(true){//wang qian tiao
				nlo+=d;
				if(nlo>=inde2loca[n]) break;
				while(true){//zhao ju ti wei zhi
					if(nlo>inde2loca[nin]){
						nin++;
					}
					else if(nlo=inde2loca[nin]){
						jumps++;
						break;
					}
					else{
						jumps++;
						nin--;
						nlo=inde2loca[nin];
						break;
					}
				} 
			}
			if(jumps==n/d && n%d==0) continue;
			for(int i=i;i<jumps;i++){
				int nlo=inde2loca[indchain[i]]-1,jmp=0,nin=indchain[i];
				while(true){//wang qian tiao
					if(nlo>=inde2loca[n]) break;
					while(true){//zhao ju ti wei zhi
						if(nlo>inde2loca[nin]){
							nin++;
						}
						else if(nlo=inde2loca[nin]){
							jmp++;
								break;
						}
						else{
							jmp++;
							nin--;
							nlo=inde2loca[nin];
							break;
						}
					}
					nlo+=d;
				}
				if (jmp+i==jumps){
					if(ans[l][r]==false) ans[l][r]=true;
					else{
						ans[l][r]=false;
						break;
					}
				}
			}
		}}
		int finans=0;
		for(int i=0;i<2000005;i++){for(int j=0;j<2000005;j++){
			if (ans[i][j]==true) finans++;
		}}
		cout << finans << endl;
	}
}
