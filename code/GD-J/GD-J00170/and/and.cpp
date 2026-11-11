#include <bits/stdc++.h>
using namespace std;
int a[200010];
bool pos[200010];
bool lpos[200010];
int mi[32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;++i){
		cin >> a[i];
		pos[i]=1;
		lpos[i]=1;
	}
	int mia=1;
	for(int i=0;i<32;++i){
		mi[i]=mia;
		mia=mia*2;
	}
	int ans=0;
	int po=0;
	for(int i=31;i>=0;i--){
		po=0;
		for(int j=0;j<n;++j){ 
			if ((a[j]%mi[i+1])/mi[i]==1&&pos[j]==1){
				++po;
			}
			else pos[j]=0;
		}
		if (po<m){
			for(int j=0;j<n;++j)pos[j]=lpos[j];
		}
		else ans+=mi[i];
		for(int j=0;j<n;++j)lpos[j]=pos[j];
	}
	cout << ans;
	return 0;
} 
