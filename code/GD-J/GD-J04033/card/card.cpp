#include<bits/stdc++.h>
using namespace std;
vector<int> t;
int x[0x3f3f3f];
map<int,int> f; 
map<int,int> p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		int y;
		cin>>y;
		t.push_back(y);
		p[y]=i;
	}
	for(int i=0;i<b;i++){
		cout<< i ;
	}
	return 0;
} 
