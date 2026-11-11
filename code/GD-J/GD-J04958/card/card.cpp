#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m;
int a[N],b[M],d[N],e[N],g[M],h[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		d[i]=a[i];
		h[a[i]]=i;
	}
	for(int i=0;i<n;i++){
	    int cnt=1;
		for(int i=0;i<n;i++){
			a[i]=d[i];
		}
		for(int i=0;i<n;i++){
			int t;
			if(a[i]==0) continue;
			if(b[a[i]]>0){
				t=a[i];
				a[i]=0;
				d[i]=0;
				for(int j=b[t];j<cnt;j++){
					d[h[e[j]]]=e[j];
					e[j]=0;
				}
				cnt=b[t];
			}
			e[cnt]=t;
			b[t]=cnt;
			cnt++;
		}
		for(int i=1;i<cnt;i++){
			g[e[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<g[i]<<' ';
	}
	return 0;
} 
