#include<bits/stdc++.h>
using namespace std;
char a[505];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int y,d=1,z=0;
	char e;
	for(int i=1;i<=n;i++){
		cin>>y>>e;
		for(int j=d;j<=d+y-1;j++){
			a[j]=e;
		}
		d=d+y;
	}
	int m=0;
	if(d%2==0){
		m=d/2;
	}else{
		m=(d-1)/2;
	}
	for(int i=1;i<=m;i++){
		for(int j=n;j>=n-m+1;j--){
			if(a[i]!=a[j]){
				z++;
			}
		}
	}
	cout<<z<<endl;
	return 0;
}
