#include<iostream>
#include<stack>
#include<cstdio>
#include<map>
using namespace std;
using ll=long long;
const int Mn=200000+5;
map<int,ll>Map;
stack<ll>Stck;
ll N,M,Cds[Mn],Pfx[Mn],Ans[Mn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&N,&M);
	for(int I=1;I<=N;I++){
		scanf("%lld",&Cds[I]);
		if(Map.find(Cds[I])!=Map.end()){
			Pfx[I]=Map[Cds[I]];
			Map[Cds[I]]=I;
		}else{
			Pfx[I]=0;
			Map[Cds[I]]=I;
		}
	}
	for(int I=1;I<=N;I++){
		Stck.push(Cds[I]);
		int LstIdx=Pfx[I];
		for(int J=I+1;J<=N;J++){
			if(Pfx[J]>LstIdx){
				int Card=Cds[J];//Top Card Code;
				while(!Stck.empty()||Stck.top()!=Card)Stck.pop();
				if(!Stck.empty())Stck.pop();
				LstIdx=Pfx[J];
			}
			Stck.push(Cds[J]);
		}
		//Check();
		while(!Stck.empty()){
			int Top=Stck.top();
			Ans[Top]++;
			Stck.pop();
		}
	}
	Ans[Cds[N]]=N;//Last Card 'll be appeared in all games.
	for(int I=1;I<=M;I++)printf("%lld ",Ans[I]);
	return 0;
}

