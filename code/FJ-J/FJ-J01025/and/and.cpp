#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mbit,v[200005],ans;
int pand(int x,int y){
	x&=y;
	return x;
}
bool cmp(int a,int b){
	return a>b;
}
vector<int> g[31];
int find(int w,int s){
	if(w<0) return 0;
	int r;
	for(int j=0;j<s;j++){
		if(pand(v[j],pow(2,w))==pow(2,w)) r++;
	}
	if(r>=m){
		int jr=0;
		for(int j=0;j<s;j++){
			if(pand(v[j],pow(2,w))==pow(2,w)){
				v[jr]=v[j];
				jr++;
			}
		}
		return pow(2,w)+find(w-1,r);	
	}
	return find(w-1,s);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if(pow(2,j)>a[i]) break;
			if(pand(a[i],pow(2,j))==pow(2,j)){
				g[j].push_back(a[i]);
				mbit=max(mbit,j);
			}
		}
	}
	for(int i=mbit;i>=0;i--){
		if(g[i].size()<m) continue;
		for(int j=0;j<g[i].size();j++){
			v[j]=g[i][j];
		}
		
		ans=pow(2,i)+find(i-1,g[i].size());
		break;
	}
	cout<<ans;
	return 0;
} 
