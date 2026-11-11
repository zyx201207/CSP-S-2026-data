#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005]={};
vector <int> v,v1;
int finding(int x){
	for(int i=0;i<(int)v.size();i++) if(v[i]==x) return i;
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			int op=finding(a[i]);
			if(op!=-1){
				v1.clear();
				for(int j=0;j<op;j++) v1.push_back(v[j]);
				v.clear();
				for(int j=0;j<(int)v1.size();j++) v.push_back(v1[j]);
			}
			v.push_back(a[i]);
		}
		for(int i=0;i<(int)v.size();i++) b[v[i]]++;
		v.clear();
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
}
