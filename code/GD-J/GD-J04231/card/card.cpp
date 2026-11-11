#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>num;
vector<int>a;
vector<int>table;
int main(){
	bool b=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		num.push_back(k);
	}
	for(int i=1;i<n;i++){			
		if(a[0]==a[i])b=0;
	}
	if(b){
		for(int i=0;i<m;i++){
			cout<<1<<" ";
		}
	}
}
