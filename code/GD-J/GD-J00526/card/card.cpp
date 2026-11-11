#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n,0);
	vector<int> js(m+1,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		vector<int> b(m+1,0);
		for(int j=i;j<n;j++){
			if(b[a[j]]==0){
				b[a[j]]++;
			}else{
				int jk=j;
				while(a[--jk]!=a[j]){
					b[a[jk]]=0;
				}
			}
		}
		for(int j=0;j<m;j++){
			if(b[j+1]){
				js[j+1]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<js[i]<<" ";
	}
	return 0;
}
