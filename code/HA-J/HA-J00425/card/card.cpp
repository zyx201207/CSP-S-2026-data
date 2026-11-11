#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N],b[N],sum[N];

struct node{
	int xb;
	int sz;
}t[N];
int d;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);

	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	for(int j=0;j<n;j++){
		
		for(int v=0;v<n;v++)
			t[v].xb=t[v].sz=0;
		
		for(int i=j,xb=0;i<n;i++,xb++){
			if(!t[a[i]].sz){
				t[a[i]].sz++;
				t[a[i]].xb=xb;
				b[xb]=a[i];
			}
			else{
				for(int v=t[a[i]].xb+1;v<=xb;v++){
					t[b[v]].sz=t[b[v]].xb=0;
				}
				xb=t[a[i]].xb;
			}
			d=xb;
		}
		while(d>=0)
			sum[b[d--]]++;
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<' ';
	
	
	return 0;
}