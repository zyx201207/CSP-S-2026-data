#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	int l=0,r=n;long long T=0;
	char c[1001];
	int a[101010];
	for(int i=0;i<n;i++) {
		cin>>a[i]>>c[i];
	}	
	for(int i=l;i<r;i++) {
		if(c[l]==c[r-1]) {
			l++,r--;
		}
		else if(c[l]!=c[r-1]){
			T=T+a[r-1];
			c[r-1]=c[l];
			c[r--];	
		} 
	}
	cout<<T;
	if(n==1){
		cout<<0;
		return 0;
	}	
}
