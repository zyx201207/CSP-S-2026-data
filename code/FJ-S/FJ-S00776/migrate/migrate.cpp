#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5;
int c,T;
int n,d,x[N];
int cnt[N][N],f[N][N],ans;

void check(int p,int q,int z){
	int s=f[p][z]+f[z][q];
	if(s==f[p][q])
		cnt[p][q]++;
	else if(s<f[p][q]){
		cnt[p][q]=1;
		f[p][q]=f[q][p]=s;
	}
}

int search(){
	int num=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2)
				num++;
		}
	}
	return num;
}

void mem(){
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=1e10;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(abs(x[i]-x[j])<=d)
				f[i][j]=1;
		}
	}	
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		mem();   
		for(int k=1;k<=n;k++)
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
					check(i,j,k); 
		cout<<search()<<"\n";
	}
	return 0;
}
