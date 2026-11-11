#include<bits/stdc++.h>
using namespace std;
char a[20001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}

	char c[100];
	long long y=0;
	int m[100];
	for(int i=0;i<n;i++){
		cin>>m[i]>>c[i];
		for(int j=0;j<m[i];j++){
			a[y]=c[i];
			y++;
		}
	} 
	bool b=0;
	if(n==1){
		cout<<"0";
		return 0;
	}
	if(n==2){
		if(m[0]>m[1]){
			cout<<m[1];
			return 0;
		}else if(m[0]<=m[1]){
			cout<<m[0];
			return 0;
		}
	}
	for(int i=0;i<y/2;i++){
		if(a[i]!=a[y-i-1])sum++;
	}
	cout<<sum;
	return 0;
} 
