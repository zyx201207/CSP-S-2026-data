#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a="";
	int n;
	cin>>n;
	int j=-1;
	for(int i=1;i<=n;i++){
		int k;
		char c;
		cin>>k>>c;
		for(int num=1;num<=k;num++){
			j++;
			a[j]=c;
		}
	}
	int sum=0;
	for(int i=1;i<=j/2;i++){
		if(a[i-1]!=a[j-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

