//GZ-J00659 »ÆºÆª 
#include<bits/stdc++.h>
using namespace std;
int a[1000010];int n,m,ma=0;
struct tree{
	int cnt=0,l0=-1,r1=-1;
};
struct fid{
	int to,de,is;
};
int cnts=1;
tree ssb[5000010];
int find(){
	int jjs=0;
	int ans=0;
	while(1){
		if(ssb[jjs].l0==ssb[jjs].r1&&ssb[jjs].l0==-1){break;}
		ans<<=1;
		if(ssb[ssb[jjs].r1].cnt>=m){ans+=1;jjs=ssb[jjs].r1;}
		else{jjs=ssb[jjs].l0;}
	}return ans;
}
void out(){
	queue<fid>q;
	q.push({0,0,0});
	int de=0,cnts1=0,cnts2=0;
	while(!q.empty()){
		fid p=q.front();
		q.pop();
		int ad=ssb[p.to].cnt;
		if(p.de>de){
			de=p.de;
			//cout<<" "<<de<<endl;
			cnts1=0;cnts2=0;
		}
		ssb[p.to].cnt+=(p.is?cnts1:cnts2);
		if(p.is){cnts1+=ad;}
		cnts2+=ad;
		//cout<<ssb[p.to].cnt<<" ";
		if(ssb[p.to].r1!=-1){q.push({ssb[p.to].r1,p.de+1,1});}
		if(ssb[p.to].l0!=-1){q.push({ssb[p.to].l0,p.de+1,0});}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		s=0;ssb[s].cnt++;
		for(int j=31,b=a[i]>>j;j>-1;j--,b=a[i]>>j){
			if(b&1){
				if(ssb[s].r1==-1){ssb[s].r1=cnts;cnts++;}
				s=ssb[s].r1;
			}else{
				if(ssb[s].l0==-1){ssb[s].l0=cnts;cnts++;}
				s=ssb[s].l0;
			}ssb[s].cnt++;
		}
	}
	out();
	cout<<find();
	return 0;
}
