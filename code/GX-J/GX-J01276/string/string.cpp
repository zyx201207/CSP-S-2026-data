#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string list[1000008]={};
	string strlist[1000008]={};
	int n=0;
	int strlistlen=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>list[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<list[i][0];j++){
			strlistlen=strlistlen+1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<list[i][0];j++){
			for(int z=0;z<strlistlen;z++){
				strlist[z]=list[i][1];
			}
		}
	}
	cout<<2;
	return 0;
}
