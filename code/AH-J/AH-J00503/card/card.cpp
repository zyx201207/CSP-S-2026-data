#include<bits/stdc++.h>
using namespace std;
string pai="",zhuo="";
int mm[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string d;
		cin>>d;
		pai+=d;
	}	
	for(int i=0;i<pai.size();i++){
		for(int j=i;j<n;j++){
			if(zhuo.find(pai[j])!=string::npos)zhuo.erase(zhuo.find(pai[j]),zhuo.size());
			zhuo+=pai[j];
		}
		for(int j=1;j<=m;j++){
			if(zhuo.find(j)!=string::npos)mm[j]++;
		}
		zhuo.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<mm[i]<<" ";
	}
	return 0;
}
