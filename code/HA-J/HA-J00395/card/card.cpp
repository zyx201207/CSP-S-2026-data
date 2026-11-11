#include<bits/stdc++.h>
using namespace std;
vector <int> v;
int n,m,a[500009],b[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	v.push_back(a[0]);
	for(int i=2;i<=n;i++){
		int l=v.size(),f=0;
		for(int j=0;j<l;j++){
			if(v[j]==a[i]){
				f=j;
				break;
			}
		}
		if(f!=0){
			v.erase(v.begin()+f);
			v.push_back(a[i]);
		}else{
			v.push_back(a[i]);
		}
		l=v.size();
		for(int j=0;j<l;j++){
			b[v[i]]++;
		}
	}
	b[a[0]]++;
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
