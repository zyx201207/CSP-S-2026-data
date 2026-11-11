#include<bits/stdc++.h>
typedef int ll;
using namespace std;
typedef struct zyb{
	bool a;
	int wa;
}fl;
int main(){
	ifstream fin("card.in");
	ofstream fout("card.out");
	int n,m;
	fin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		fin>>a[i];
	}
	fl fa[m];
	int ans[m]={0};
	for(int i=0;i<n;i++){
		int c[n];
		for(int j=i;j<n;j++){
			if(fa[a[j]].a){
				for(int k=c[fa[a[j]].wa];k<j;k++){
					fa[c[k]].a=false;
					fa[a[j]].wa=0;
					c[k]=0;
				}
			}else{
				fa[a[j]].a=true;
				c[j]=a[j];
				fa[a[j]].wa=j;
			}
		}
		for(int j=0;j<n;j++){
			ans[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		fout<<ans[i];
	}
	fin.close();
	fout.close();
	return 0;
} 
