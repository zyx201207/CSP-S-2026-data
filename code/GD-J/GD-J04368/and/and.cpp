#include <bits/stdc++.h> 
using namespace std;
#define cin fin
#define cout fout
ifstream fin("and.in");
ofstream fout("and.out");
long long po(int x){
	long long ans=1;
	for(int i=0;i<x;i++) ans*=2;
	return ans;
}
bool b[32][200005]={};
bool a[200005]={};
int main(){
	int n,m,g,p,l=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>g;
		p=0;
		while(g>=2){
			if(g%2==1) b[p][i]=1;
			p++;
			g/=2;
		}
		b[p][i]=1;
		if(p>l) l=p;
	}

	int nu=0;
	long long ans=0;
	for(int i=l;i>=0;i--){
		nu=0;
		for(int j=0;j<n;j++){
			if(b[i][j]==1&&a[j]==0) nu++;
		}
		if(nu>=m){
			for(int j=0;j<n;j++){
				if(b[i][j]==0) a[j]=1;
			}
			ans+=po(i);
		}
	}
	cout<<ans;
	return 0;
}
