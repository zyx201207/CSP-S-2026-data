#include<bits/stdc++.h>

using namespace std;

int c,n,m,d,q;
int w[510];
int a[20010][20010];

void dij(int b,int e){
	queue<int> qu;
	qu.push(b);
	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>w[i];
	for(int i=0;i<n;i++){
		int k,v[40],to[40];
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>to[j]>>v[j];
			for(int x=0;x<j;x++){
				if(a[to[j]][to[x]]) a[to[j]][to[x]]=min(a[to[j]][to[x]],v[j]+v[x]);
				else a[to[j]][to[x]]=v[j]+v[x];
			}
		}
	}
	
	for(int i=0;i<q;i++){
		int b,e;
		cin>>b>>e;
		cout<< dij(b,e)+w[b-1]+w[e-1] << endl; 
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
