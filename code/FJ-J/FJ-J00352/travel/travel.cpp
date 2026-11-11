#include<bits/stdc++.h>
using namespace std;
string aa,ab,ba,bb;
int ax,ay,ah,bx,by,bh,f[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>aa>>ab>>ba>>bb;
	for(int i=0;i<=1;++i){
		ax*=10;
		ax+=aa[i]-'0';
		ay*=10;
		ay+=ab[i]-'0';
		bx*=10;
		bx+=ba[i]-'0';
		by*=10;
		by+=bb[i]-'0';
	}
	ah=ab[2]-'A'+1;
	bh=bb[2]-'A'+1;
	if(ax==bx){
		f[1]=1;
	}
	if(ay==by){
		f[2]=1;
	}
	if((ah<=3&&bh<=3)||(ah>=4&&bh>=4)){
		f[3]=1;
	}
	if(min(ah,bh)+1==max(ah,bh)){
		f[4]=1;
	}
	bool pd=false;
	for(int i=1;i<=4;++i){
		if(pd==true){
			cout<<0;
		}else{
			if(f[i]==0){
				pd=true;
			}
			cout<<f[i];
		}
	}
	cout<<endl;
	return 0;
}

