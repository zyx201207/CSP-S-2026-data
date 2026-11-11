#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
int n,m,x[10005],y,s[10002];
ll a[10000005],b[10000005],c[10000005];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>x[i];
	}
	int r=1;
while(m>0){
	y=m%2;
	a[r]=y;
	r++;
	m=m/2;
	}
	int q=1;
for(int i=1;i<=n;i++){
while(x[i]>0){
	y=x[i]%2;
	b[q]=y;
	q++;
	x[i]=x[i]/2;
	}
if(r<q)swap(r,q);
int l=1;
for(int v=r;v>=1;v--){
	if(a[v]==b[v] and a[v]==1) c[l]=1;
	l++;
	}
	int f=l-1;
for(int u=1;u<=l;u++){
	for(int p=1;p<=f;p++){c[u]*=c[u];}
	s[i]+=c[u];
	f--;
	}	
	}
	sort(s+1,s+n+1);
	cout<<s[n];
	
return 0;
}


