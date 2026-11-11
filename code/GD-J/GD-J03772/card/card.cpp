#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("card.in");
	ofstream fout("card.out");
	int n,m;
	fin>>n>>m;
	int a[n],cnt[m+1],v[m+1];
	for(auto&i:cnt)
		i=0;
	for(auto&i:a)
		fin>>i;
	for(int k=0;k<n;++k){
		for(auto&i:v)
			i=0;
		stack<int>s;
		for(int i=k;i<n;++i){
			if(v[a[i]]){
				while(1){
					--v[s.top()];
					if(s.top()==a[i]){
						s.pop();
						break;
					}
					s.pop();
				}
			}
			++v[a[i]];
			s.push(a[i]);
		}
		while(!s.empty()){
			++cnt[s.top()];
			s.pop();
		}
	}
	for(int i=1;i<=m;++i)
		fout<<cnt[i]<<" ";
	return 0;
}
