#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	int n,m,a,sum[n],num=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		sum[a];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(sum[i]%sum[j]>num){
				num=sum[i]%sum[j];
			}
		}
	}
	cout<<num;
	return 0;
}
