#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num=0;
	cin >> n;
	long long a[n];
	char b[n];
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
	}
	if(n==1){
		cout << 0;
		return 0;
	}
	int x=0;
	for(int i=1;i<n;i++){
		if(b[i]==b[i+1]){
			x=1;
		}else{
			break;
		}
	}
	if(x==1){
		cout << 0;
		return 0;
	}
	int xxx=0;
	for(int i=1;i<=n;i++){
		xxx+=a[i]; 
	}
	char qp[xxx],op=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			qp[op]=b[i];
		}
		op++;
	}
	for(int i=1;i<=xxx;i++){
		if(qp[i]!=qp[xxx-i]){
			qp[xxx-i]=qp[i];
			num++;
		}
	}
	cout << num;
	return 0;
} 
