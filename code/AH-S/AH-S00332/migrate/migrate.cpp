#include<bits/stdc++.h>
using namespace std;
int L[2000001],R[2000001];
long long x[2000001],d;
vector<pair<int,int> > V;
vector<int> LV,RV,LDis,RDis;
void G_1112(int n){
	if(n==1){
		printf("0\n");
		return;
	}
	long long u=x[2]-x[1];
	long long k=d/u;
	if(k<=1){
		printf("0\n");
		return;
	}
	int now=2*k-1;
	if(now>=n){
		printf("0\n");
		return;
	}
	printf("%d\n",n-now);
	return;
}
void GO(int c){
	/*Input*/
	int n;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	int sr=1;
	for(int sl=1;sl<=n;sl++){
		while(sr<n&&x[sr+1]-x[sl]<=d)sr++;
		R[sl]=sr;
	}
	int tl=n;
	for(int tr=n;tr>=1;tr--){
		while(tl>1&&x[tr]-x[tl-1]<=d)tl--;
		L[tr]=tl;
	}
	if(c==11||c==12){
		G_1112(n);
		for(int i=1;i<=n;i++)x[i]=L[i]=R[i]=0;
		V.clear();LV.clear();RV.clear();LDis.clear();RDis.clear();
		return;
	}
	//for(int i=1;i<=n;i++)cerr<<L[i]<<" "<<R[i]<<endl;
	/*Deal with Limit Points*/
	for(int i=1;i<=n;i++)if(R[i]!=R[i-1])V.push_back(make_pair(i,R[i]));
	int u=V.size();
	//for(int i=0;i<u;i++)cerr<<V[i].first<<" "<<V[i].second<<endl;
	LV.resize(u);RV.resize(u);
	LDis.resize(u,0);RDis.resize(u,0);
	int lstl=0;
	for(int i=0;i<u;i++){
		while(V[lstl].second<V[i].first)lstl++;
		if(V[lstl].second==V[i].first){
			LV[i]=LV[lstl];
			LDis[i]=LDis[lstl];
		}
		else{
			LV[i]=i;
			LDis[i]=0;
		}
		if(i<u-1&&V[i+1].first<V[i].second)LDis[i]+=(V[i].second-V[i+1].first);
	}
	int lstr=u-1;
	for(int i=u-1;i>=0;i--){
		while(V[lstr].first>V[i].second)lstr--;
		if(V[lstr].first==V[i].second){
			RV[i]=RV[lstr];
			RDis[i]=RDis[lstr];
		}
		else{
			RV[i]=i;
			RDis[i]=0;
		}
		if(i>0&&V[i-1].second>V[i].first)RDis[i]+=(V[i-1].second-V[i].first);
	}
	for(int i=0;i<u;i++)assert(LDis[i]<=n && RDis[i]<=n && V[i].first>=1 && V[i].second<=n && LV[i] >=0 && LV[i]<=RV[i] && RV[i]<u);
	//for(int i=0;i<u;i++)cerr<<LV[i]<<" "<<RV[i]<<endl;
	/*Compute*/
	long long ans=0;
	int nR=0;
	for(int i=0;i<u-1;i++){
		while(nR<u-1&&V[nR].first<V[i].second-1)nR++;
		if(V[nR].first!=(V[i].second-1))continue;
		if(nR<=i)continue;
		ans=ans+1ll*(V[RV[nR]].second-V[nR].first-RDis[nR])*(V[i].second-V[LV[i]].first-LDis[i]);
		//assert(abs(ans)<=1e13);
		//if(i%1000==0)cerr<<i<<" "<<1ll*(V[RV[nR]].second-V[nR].first-RDis[nR])*(V[i].second-V[LV[i]].first-LDis[i])<<endl;
	}
	printf("%lld\n",ans);
	/*Clear*/
	for(int i=1;i<=n;i++)x[i]=L[i]=R[i]=0;
	V.clear();LV.clear();RV.clear();LDis.clear();RDis.clear();
	d=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--)GO(c);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
