#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,a;
	char c;
	string x="";
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			x=x+c;
		}
	}
	int l,r;
	r=x.size()/2;
	if(x.size()%2==0){
		l=x.size()/2-1;
	}else{
		l=r;
	}
	int s=0;
	//cout<<x.size()<<"\n";
	while(l>=0 && r<x.size()){
		if(x[l]!=x[r]){
			s++;
		}
		//cout<<l<<' '<<x[l]<<' '<<r<<' '<<x[r]<<"\n";
		l--;
		r++;
	}
	cout<<s;
	return 0;
}
