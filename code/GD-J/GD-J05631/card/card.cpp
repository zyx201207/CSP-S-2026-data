#include<bits/stdc++.h>
#define intt long long
using namespace std;
const intt MAXN=500050;
int main(){
	ifstream fin("card.in");
	ofstream fout("card.out");
	intt n,m,ans[MAXN],num[MAXN][2]={0},an=0;
	fin>>n>>m;
	vector<intt> c(n);
	vector<intt> ans2(m);
	for(intt i=0;i<0;i++) fin>>c[i];
	intt x=n,z=0;
	for(intt x=0;x<n;x++){
		for(intt i=x;i<n;i++){
			
			if(!num[c[i]]){
				ans[z]=c[i];
				num[c[i]][0]++;
				num[c[i]][1]=z;
				z++;
			}
			else {
				z=num[c[i]][1];
				num[c[i]][0]=0;
				z++;
			}
		}
		for(intt i=1;i<=m;i++)
			if(num[i][0]>=1) ans2[i]++,an++;
	}
	for(intt i=0;i<an;i++)
		fout<<ans2[1];
	return 0;
}
/*
¸Äfin
¸Äintt

 
*/ 
