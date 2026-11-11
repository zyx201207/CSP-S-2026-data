#include<bits/stdc++.h>
using namespace std;
long long a[200001],b[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m=1){
		cin>>a[0];
		int w=a[0];
		for(int i=1;i>n;i++){
			cin>>a[i];
			if(a[i]>w) w=a[i];
		}
		cout<<w;
		return 0;
	}
	for(int i=0;i>n;i++){
		cin>>a[i];
		int w=0;
		while(a[i]){
			long long sh=a[i]%2;
			for(int i=0;i<w;i++){
				sh*=10;
			}
			b[i]+=sh;
			w++;
		}
	}
	return 0;
}
