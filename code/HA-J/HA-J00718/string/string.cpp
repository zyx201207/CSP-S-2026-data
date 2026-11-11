#include<bits/stdc++.h>
using namespace std;
int n,a[50500];
char c[50500];
string x;
long long ans=1;
int cu=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			x[ans]=c[i];
			ans+=1;
		}
	}
	for(int i=1;i<=ans-1;i++){
		if(x[i]!=x[ans-i]){
			cu+=1;
		}
	}
	cout<<cu/2;
	return 0;
}
