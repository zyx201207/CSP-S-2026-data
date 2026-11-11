#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],anss[N],mama;
bool is[N];
int n,m;
void maxx(int x){
	if(x==m){
		for(int i=1;i<m;i++){
			anss[i]=anss[i-1]&anss[i];
		}
		mama=max(mama,anss[m-1]);
		return ;
	}
	for(int i=0;i<n;i++){
		if(!is[i]){
			anss[x]=a[i];
			is[i]=true;
			maxx(x++);
			is[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long ans=0;
	cin >>n >>m;
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	maxx(0);
	cout <<mama;
	return 0;
}
