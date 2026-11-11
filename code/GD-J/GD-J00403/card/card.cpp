#include <bits/stdc++.h>
using namespace std;
struct node{
	int idx,next,last;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int ans[m+1];
	for (int i=0;i<=m;i++) ans[i]=0;
	for (int i=0;i<=m;i++) ans[m+1]=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> table;
	for (int i=1;i<=n;i++){
		table.push_back(a[i]);
		int k=0;
		for (int j=i+1;j<=n;j++){
			int now=a[j];
			int kb=0;
			for (int p=0;p<table.size();p++){
				if (table[p]==now){
					kb=table.size()-p+1;
					break;
				}
			}for (int r=0;r<kb;r++) table.pop_back();
		}
		for (auto e:table){
			ans[e]++;
		}
	}
	for (int a=1;a<=m;a++){
	cout<<"fas";
		cout<<ans[a]<<' ';
	}
	cout<<endl;
	return 0;
}
