#include<bits/stdc++.h>
using namespace std;
const int M=1e6;
int n,m;
int t=0;
long long a[M];
long long b[M];
long long ans[M];
bool f[M];
void init();
void work();
void print();
void init(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(b,-1,sizeof(b));
	memset(f,0,sizeof(f));
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++) cin>>a[i];
}
void work(){
	for(int i=1;i<=n;i++){
		t=0;
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			t++;
			b[t]=a[j];
			//cout<<t<<"?"<<' ';
			if(f[a[j]]==1){
				int z=0;
				for(int x=1;x<=t;x++){
					if(b[x]==a[j]){
						z=x;
						break;
					}
				}
				t=z;
				for(int k=z+1;k<=t-1;k++) f[a[k]]=0;
				//cout<<z<<"+"<<' '; 
			}
			f[a[j]]=1;
			//cout<<t<<"!"<<' '; 
		}
		for(int v=1;v<=t;v++){
			ans[b[v]]++;
		}
		/*
		for(int d=1;d<=m;d++) cout<<ans[d]<<' ';
		cout<<t<<endl;
		*/
	}
}
void print(){
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}
int main(){
	init();
	work();
	print();
	return 0;
} 
