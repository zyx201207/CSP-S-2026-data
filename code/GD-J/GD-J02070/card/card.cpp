#include<iostream>

using namespace std;

long long a[500010],b[300010],x,c[300010];
void check(long long now){
	for(long long i=1;i<x;i++){
		if(b[i]==now){
			x=i;
			return ;
		}
	}
	return ;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		x=0;
		for(int j=i;j<=n;j++){
			x++;
			b[x]=a[j];		
			check(b[x]);
		}
		for(long long j=1;j<=x;j++){
			c[b[j]]++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
