#include<bits/stdc++.h> 
using namespace std;
string s="";

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a;
	cin>>a;
	int n;
	string m;
	for(int i=0;i<a;i++){
		cin>>n>>m;
		
	}
	string o="";
	for(int i=0;i<a;i++){
		for(int j=0;j<n;j++){
			o=o+m; 
		}
	}
	string h="";
	for(int i=o.size();i>-1;i--){
		h=h+o[i];
	}
	int l=int (o.size()),u=0;
	if(h==o){
		cout<<0;
	}

	else{
		for(int i=0;i<int (o.size());i++){
			o[l]=o[u];
			for(int i=o.size();i>-1;i--){
				h=h+o[i];
				}
			if(h==o){
				cout<<u;
				break;
			}
			l--;
			u++;
		}
	}
	
}
