#include<bits/stdc++.h>
#define intt long long
using namespace std;
int main(){
	ifstream fin("and.in");
	ofstream fout("and.out");
	intt n,m,ans=0,co=0;
	fin>>n>>m;
	vector<intt> num(n);
	for(intt i=0;i<n;i++) fin>>num[i];

	for(intt i=0;i<n;i++)
		for(intt j=i+1;j<i+m;j++){
			co=num[i]&num[j];
			ans=max(ans,co);
		}
	fout<<ans;
	return 0;
}
/*
¸Äfin
¸Äintt

 
*/ 

