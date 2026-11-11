#include<bits/stdc++.h>
using namespace std;
long long a,s,n,m,w,e[1000005],ma=-9999999,r[1000000];
long long q[1000][1000];
void qh(long long z,long long x){
	if(x==1){
		for(int i=1;i<=n;i++){//dp
		if(r[i]==1)continue;
			ma=max(ma,z&e[i]);
		}
	}else{
		for(int i=1;i<=n;i++){//dp
			if(r[i]==1)continue;
			r[i]=1;
			qh(e[i]&z,x-1);
			r[i]=0;
			
		}
	}
	
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){//dp
		cin>>e[i];
	}
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++){//dp
		r[i]=1;
		qh(e[i],m-1);
		r[i]=0;
	}
	cout<<ma;
	
	/*
	for(int i=1;i<=n;i++){//dp
		cin>>w;
		
		for(int o=2;o<=m;o++){if(i==1)q[0][o]=w;
			q[i][o]=max(q[i-1][o],q[i][o-1]&w);cout<<1;
		}
	}
	for(int i=1;i<=n;i++){//dp
		for(int o=1;o<=m;o++){
			cout<<q[i][o]<<" ";
		}
		cout<<endl;
	}*/
	
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7


*/
