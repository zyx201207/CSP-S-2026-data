#include<bits/stdc++.h>
#define intt long long
using namespace std;
struct task2{
	intt m;
	char s;
};
int main(){
	ifstream fin("string.in");
	ofstream fout("string.out");
	intt n,c=0,ans=0;
	fin>>n;
	vector<task2> a(n);
	for(intt i=0;i<n;i++)
		fin>>a[i].m>>a[i].s,c+=a[i].m;
	string r1;
	for(intt i=0;i<n;i++){
		for(intt j=0;j<a[i].m;j++)
			r1+=a[i].s;
	}
	
	intt j=0;
	for(intt i=c-1;i>=0;i--){
		if(r1[i]!=r1[j]){
			ans++;
			r1[i]=r1[j];
			r1[j]=r1[i];
		}
		++j;
	}
	fout<<ans;
	return 0;
}
/*
¸Äfin
¸Äintt

 
*/ 
