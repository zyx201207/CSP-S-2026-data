#include<bits/stdc++.h>
using namespace std;
int b[500005],c[500005],d[500005],n,m;
vector<int> a[300005];
void f(int x,int z){
	if(x==n-1){
		for(int i=z;i<n;i++){
			b[d[i]]++;
		}
		return;
	}
	int y=a[d[x]][a[d[x]].size()-1];
	for(int i=x;i<y;i++){
		d[i]=0;
	}
	if(x<y){
		f(y,z);
	}else{
		f(x+1,z);
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
		a[c[i]].push_back(i);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			d[j]=c[j];
		}
		f(i,i);
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
