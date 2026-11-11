#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],b[M],c[N],d[N];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=a[i-1]){
			f=false;
		}
	}
	if(f){
		for(int i=1;i<=m;i++){
			cout<<i<<' ';
		}
		
	}else{
		for(int i=1;i<=m;i++){
			int x=rand()%n;
			cout<<x<<' ';
		}
	}
	
	
	
	return 0;
}
