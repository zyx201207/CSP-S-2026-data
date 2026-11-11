#include<bits/stdc++.h>
using namespace std;
queue<long long> q1,q2;
vector<long long>vec,tpc;
long long n,m,i,k1,k2,k3;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	//n是牌数量，m是点数，也就是有多少类型的种类 
	vec.resize(m+1,0);
	tpc.resize(n+1,0);
	bool pf=true;
	long long old=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&k1);
		if(pf&&i>1){if(k1<old)pf=false; 
		}
		tpc[i]=k1;//这是顺序 
	}
	if(pf){
		for(int i=1;i<=m;i++){
			printf("%d",&i);
		}return 0;
	}
	int i=0;
	while(i<=n){
		i++;
		while(!q1.empty()){
			q1.pop();
		}
		while(!q2.empty()){
			q2.pop();
		}
		bool fal=false;
		for(int j=i;j<=n;j++){//这是抽牌进去的一个过程 
			k1=tpc[j];
			if(fal==false){
			while(!q1.empty()){
				k2=q1.front();
				q1.pop();
				if(k2==k1){
					break;
				}
				q2.push(k2);
			}q2.push(k1);fal=true;}
			else {
				while(!q2.empty()){
				k2=q2.front();
				q2.pop();
				if(k2==k1){
					break;
				}
				q1.push(k2);
			}q1.push(k1);fal=false;
			} 
			}int qsz;
			if(fal==true)qsz=q2.size();
			else qsz=q1.size();
			for(int i=1;i<=qsz;i++){
				if(fal==true){
				k3=q2.front();
				q2.pop();
				vec[k3]++;}
				else{
				k3=q1.front();
				q1.pop();
				vec[k3]++;
				} 
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld\n",vec[i]);
	}
}
