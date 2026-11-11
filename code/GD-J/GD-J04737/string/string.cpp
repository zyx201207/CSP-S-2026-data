#include<bits/stdc++.h> 
using namespace std;
int n,a[200005],d=0,e=0;
char c[200005],b[200000000];
int main(){
	//freopen("string.in","r",)
	//freopen("string.out","w",)
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int t=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j>0;j--){
			b[t]=c[i];
			t++;
		}
		d+=a[i];
	}
	for(int i=1;i<=d/2;i++){
		if(b[i]!=b[d-i+1]){
			e++;
		}

	}
	cout<<e;
	return 0;
}
