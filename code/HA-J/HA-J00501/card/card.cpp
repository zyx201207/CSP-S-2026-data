#include<bits/stdc++.h>
using namespace std;
int a[200005];
string y[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int p,zl;
	cin>>p>>zl;
	string w;
	for(int i=1;i<=p;i++){
		string temp;
		cin>>temp;
		w+=temp;
	}
	
	for(int i=1;i<=p;i++){
		for(int j=i-1;j<=p-1;j++){
			if(y[i][(y[i].find(w[j]))]==w[j]){
				y[i].erase(y[i].find(w[j]));
			}
			y[i]+=w[j];
		}
	}
	for(int i=1;i<=zl;i++){
		for(int j=1;j<=p;j++){
			if(y[j].find(char(i+'0'))!=-1){
				a[i]++;
			}
		}
	}
	for(int i=1;i<=zl;i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
} 
