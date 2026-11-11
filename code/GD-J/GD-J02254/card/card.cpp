#include<bits/stdc++.h>
using namespace std;

int n=0, m=0, a[1000]={0}, js[1000]={0};

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		vector<int> p;
		for(int j=i; j<=n; j++){
			p.push_back(a[j]);
			for(int k=p.size()-2; k>=0; k--){
				if(p[k]==a[j]){
					p.erase(p.begin(), p.begin()+k);
					break;
				}
			}
		}
		for(int j=0; j<p.size(); j++){
			js[p[j]]++;
		}
	}
	for(int i=1; i<=m; i++){
		cout<<js[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
