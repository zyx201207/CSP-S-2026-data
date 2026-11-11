#include<bits/stdc++.h>
using namespace std;
long long a[10000001];
long long t[10000001];
long long z[10000001];
long long er[100001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}long long k,o,l;
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			if(j%2==0){
				if(t[o]!=0){
					cin>>l;
					z[o]=l;

				}
				else{
					cin>>t[o];
				}
				
			}else{
				cin>>o;
			}
		}
	}
	long long w,e,maxn=0,h=0;
	
	while(q){
		cin>>w>>e;maxn+=a[w];
		for(int i=w;i<=e;i++){
	
				
	
			maxn+=t[i];
		}maxn+=a[e];
		for(int i=w;i<=e-1;i++)maxn+=z[i];
		er[h]=maxn;h++;
		q--;
		maxn=0;
	}for(int i=0;i<h;i++){
		cout<<er[i]<<endl;
	}return 0;}
