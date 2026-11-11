#include iostream <bits/stdc++.h>
using namespace std
int main(){
	freopen("card.in",'w',stdin)
	freopen("card.out",'r',stdout)
	int n,m;
	cin>>n>>m;
	int a=[];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int b=[];
	for(int i=0;i<n;i++){
		b[i]=a[i];
		for(int j=0;j<n;j++){
			if(b[j]==b[i]){
				for(int p=0;p<j;p++){
					b[p]=a[p];
				}
			}
		}
	}
	return 0;
}
