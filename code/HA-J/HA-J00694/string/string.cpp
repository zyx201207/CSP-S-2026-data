#include<bits/stdc++.h>
using namespace std;
long long n,e=0;
long long a[200005];
char c[200005];
string b;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			b+=c[i];
		}
	}
	if(n%2==0){
		for(int i=0;i<=n/2;i++){
			for(int j=n/2;j>=0;j--){
				if(b[i]!=b[j])e++;
			}
		}
	}else{
		for(int i=0;i<=n-(n-1)/2-1;i++){
			for(int j=n-(n-1)/2;j>=0;j--){
				if(b[i]!=b[j])e++;
			}
		}
	}
	cout<<e;
	return 0;
}