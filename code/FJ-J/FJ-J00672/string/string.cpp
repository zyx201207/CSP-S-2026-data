#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int m;
	cin>>m;
	int n[200000];
	long long x=0;
	for(int i=0;i<m;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=x;j<a;j++){
			n[j]=c-a;
		}
		x+=a;
	}
	int num=0;
	for(int i=0;i<x;i++){
		for(int j=x-1;j<=0;j--){
			if(n[i]!=n[j])
				num++;
		}
	}
	cout<<num;
	return 0;
}
