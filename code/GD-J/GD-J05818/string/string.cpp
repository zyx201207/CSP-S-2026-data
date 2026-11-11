#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m,s;
	cin>>n;
	string a;
	m=1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char y;
		cin>>y;
		for(int j=m;j<=x;j++){
			a[j]=y;
			m++;
		}
	}
	for(int i=1;i<m;i++){
		if(a[i]==a[i+1]){
			s=1;
		}else{
			s=0;
		}
	}
	if(s==1){
		cout<<0;
	}else{
		cout<<n*m/4;
	}
}
