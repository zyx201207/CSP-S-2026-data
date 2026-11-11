#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,b,c[100010],e[100010];
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	int d=c[a/2];
	for(int i=0;i<a;i++){
		e[i]=abs(c[i]-d);
	}
	int f=0,g=100000000,ans=0;
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(g>e[j]){
				g=e[j];
				f=j;
			}
		}
		if(b>=g){
			b=b-g;
			e[f]=100000000;
			ans++;
		}
		f=0,g=100000000;
	}
	cout<<ans;
	return 0;
}
