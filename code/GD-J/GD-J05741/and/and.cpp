#include<bits/stdc++.h>
using namespace std;

long long n,m,maxn;
long long N[200005];
bool Nb[200005];

void dfs(long long layer,long long w){
	if(layer>1){
		for(long long k=0;k<n;k++)
			if((w&N[k])<maxn&&Nb[k]==false)
				return ;
			else if(Nb[k]==false){
				Nb[k]=true;
				dfs(layer-1,(w&N[k]));
				Nb[k]=false;
			}
	}
	else if(layer==1){
		for(long long k=0;k<n;k++){
			if((w&N[k])>maxn&&Nb[k]==false){
				maxn=(w&N[k]);
			}
		}
	}
	else if(layer==0){
		if(w>maxn)
			maxn=w;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	maxn=0;
	for(long long i=0;i<n;i++){
		cin>>N[i];
		Nb[i]=true;
	}
	
	for(long long i=0;i<n;i++){
		Nb[i]=true;
		dfs(m-1,N[i]);
		Nb[i]=false;
	}
	
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/ 
