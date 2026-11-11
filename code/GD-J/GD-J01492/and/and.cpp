#include<iostream>
#include<algorithm>
using namespace std;
long long ma=-1;
long long l[200005];
long long n,m;
int sd(long long i,long long nw,long long w){
	if(w==m){
		ma=max(i,ma);
		return 0;
	}
	if(nw>=n)return 0;
	if(i==-1){
		sd(l[nw],nw+1,w+1);
		sd(i,nw+1,w);
		return 0;
	}
	sd(i&l[nw],nw+1,w+1);
	sd(i,nw+1,w);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	sd(-1,0,0);
	cout<<ma;
	
	return 0;
} 
