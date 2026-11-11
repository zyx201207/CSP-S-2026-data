#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int n,m;
int a[500001];
int b[300001];
void card(int iii){
	for(int i=iii;i<=n;i++){
		bool f=false;
		int ix=0;
		for(int j=0;j<v.size();j++){
			if(v[j]==a[i]){
				f=true;
				ix=j;
				break;
			}
		}
		if(f==true){
			for(int k=ix;k<v.size();k++){
				v.pop_back();
			}
		}
		v.push_back(a[i]);
	}
	for(int o=0;o<v.size();o++){
		b[v[o]]++;
	}
	v.clear();
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		card(i);
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}
