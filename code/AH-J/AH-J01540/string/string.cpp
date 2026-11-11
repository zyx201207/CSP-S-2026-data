#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,s=0;
	int a[200005];
	string c;
	string b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	for(int i=0;i<s;i++){
		for(int j=0;j<a[i];j++){
			b[i]=c[i];
		}
	} 
	for(int i=0;i<n/2;i++){
		if(b[i]==b[i+n/2+1]){
			continue;
		}
		else{
			sum+=a[i];
		}
	}
	cout<<sum;
	return 0;
}

