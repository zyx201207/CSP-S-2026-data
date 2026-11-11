#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long v[900001];
	long long g[300001];
	int a=0;
	int b=0;
	int p;
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>p;
		bool d=0;
		int k;
		for(int j=a;j<b;j++){
			if(v[j]==p){
				d=1;
				k=j;
			}
		}
		if(d){
			a=j+1;
			v[b]=v[j];
			b++;
		}
		else{
			v[b]=p;
			b++;
		}
	}
}
