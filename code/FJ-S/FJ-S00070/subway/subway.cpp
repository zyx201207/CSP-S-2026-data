#include<bits/stdc++.h>//没找到bug，没分 
#include<vector>
using namespace std;
long long int ccc,n,m,d,ques,k,am,tme,qsx,qsy,but,res;
long long int l[2][501005],h,id[501005],numb[501005];
struct stru{
	vector<long long int>a;
	vector<long long int>t;
	long long int tp,w,s,tn;//通点数，站台时间，最小距，是否到达 
}p[501005];

int divst(int lef,int rig){
	if(lef==rig)return 0;
	int mid=(lef+rig)/2;
	divst(lef,mid);
	divst(mid+1,rig);
	int pta=lef,ptb=mid+1;
	for(int ptt=lef;ptt<=rig;ptt++){
		if(pta>mid){
			numb[ptt]=id[ptb];
			ptb++;
		}else if(ptb>rig){
			numb[ptt]=id[pta];
			pta++;
		}else if(id[l[1][pta]]<id[l[1][ptb]]){
			numb[ptt]=id[pta];
			pta++;
		}else{
			numb[ptt]=id[ptb];
			ptb++;
		}
	}
	for(int ptt=lef;ptt<=rig;ptt++){
		id[ptt]=numb[ptt];
	}
	return 0;
}

int src(int unl){
	p[unl].tn=ques; 
	for(int inum=0;inum<p[unl].tp;inum++){
		h++;
		l[0][h]=p[unl].a[inum];
		l[1][h]=p[unl].t[inum]+p[unl].s;
		id[h]=h;
	}
	divst(but,h);
	return 0;
}

long long int tes(){
	but=1;
	h=0;
	src(qsx);
	while(1){
		if(p[l[0][id[but]]].tn!=ques){
			p[l[0][id[but]]].s=l[1][id[but]];
			if(l[0][id[but]]==qsy){
				return l[1][id[but]];
			}
			but++;
			src(l[0][id[but]]);
		}else{
			but++;
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&ccc,&n,&m,&d,&ques);
	for(int i=1;i<=m;i++)scanf("%lld",&p[i].w);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&am,&tme);
			p[am].a.push_back(500000+i);
			p[am].t.push_back(tme);
			p[am].tp++;
			p[500000+i].a.push_back(am);
			p[500000+i].t.push_back(tme);
			p[500000+i].tp++;
		}
	}
	while(ques--){
		scanf("%lld%lld",&qsx,&qsy);
		res=tes();
		printf("%lld\n",res);
	}
}
