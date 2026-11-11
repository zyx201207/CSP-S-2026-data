#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
vector<int> b;
vector<int> d;

int main(){
cin>>n>>m;
int c;
for(int i=0;i<n;i++){
	cin>>c;
	a.push_back(c);
}
for(int i=n-1;i>=0;i--){
	b.push_back(a[i]);
}
for(int i=1;i<=m;i++){
	d.push_back(0);
}
for(int i=0;i<n;i++){
	vector<int> e;
	int m1[400000]={0};
	for(int j=b.size()-1;j>=0;j--){
	
		if(m1[b[j]]==0){m1[b[j]]=e.size()+1;
		e.push_back(b[j]);
		}
		else {
		while(m1[b[j]]<=e.size()){
				e.pop_back();
				
			}
			e.push_back(b[j]);
		}
	}
	
	for(int j=0;j<e.size();j++){d[e[j]]++;
	
	}
	b.pop_back();
	
}




for(int i=1;i<=m;i++){
	cout<<d[i]<<' ';
}

return 0;
}
