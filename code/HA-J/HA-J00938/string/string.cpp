#include<bits/stdc++.h>
using namespace std;
struct bz{
	long long a;
	string p;
}ls[10005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int xy;
	string ly="";
	cin>>xy;
	for(int i=1;i<=xy;i++){
		cin>>ls[i].a>>ls[i].p;
		for(int j=1;j<=ls[i].a;j++){
			ly+=ls[i].p;
		}
	}
	long long yg=ly.size()-1,lyy=0;
	for(int i=0;i<ly.size()/2;i++){
		if(ly[i]!=ly[yg]){
			lyy++;
		}
		yg--;
	}
	cout<<lyy;
	return 0;
}
