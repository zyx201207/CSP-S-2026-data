#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<int> card(n),r(m+1);
	for(int i=0;i<n;i++){
		cin>>card[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<j;k++) if(card[k]!=card[j]){
				r[card[j]]++;
			}
		}
	}
	for(int i=1;i<r.size()-1;i++) cout<<r[i]<<' ';
	cout<<r[r.size()-1];
	return 0;
}
