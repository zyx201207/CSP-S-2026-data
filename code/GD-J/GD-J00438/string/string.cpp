#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	int n,a,num=0;
	char c;
	int sum[200000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>c;
		for(int j=0;j<a;j++){
			int sum[c];
			if(sum[0]!=sum[j]){
				sum[j]=sum[0];
				num++;
			}
		}
	}
	cout<<num;
	return 0;
} 
