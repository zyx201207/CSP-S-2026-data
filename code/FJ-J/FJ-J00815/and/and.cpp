#include <bits/stdc++.h> 
using namespace std;
int n,m,maxx=-1,ans=-1,cmp;
int a[200005];
int main(){
	ifstream fin("and.in");
	ofstream fout("and.out");
	fin>>n>>m;
	for(int i=0;i<n;i++){
		fin>>a[i];
		if(maxx<a[i]) maxx=a[i];
	}
	if(m==1){
		fout<<maxx;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				cmp = a[i] & a[j];
				if(ans < cmp){
					ans = cmp;
				}
			}
		}
	}
	if(m==n){
		ans=a[0];
		for(int i=0;i<n-1;i++){
			ans = ans & a[i+1];
		}
	}
	fout<<ans;
	return 0;
}
