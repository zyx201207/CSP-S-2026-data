#include <bits/stdc++.h>
using namespace std;
vector<string> a;
int m[2005];
char p[2005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>m[i];
		cin>>p[i];
	}
	int num=p[0];
	bool x=1;
	for(int i = 1;i < n;i++){
		if(num!=p[i]){
			x=0;
			break;
		} 
	}
	if(x==1){
		cout<<0<<"\n";
		return 0;
	}
	
	return 0;
}
