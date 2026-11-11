#include<bits/stdc++.h>
using namespace std;
int n,ans=0,l=0,b=0;
string d[100000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++){
		int s;
		char z;
		cin>>s>>z;
		b=l;
		for(int i=l;i<s+b;i++){
			l++;
			d[i]=z;
		}
	}
	for(int i=0;i<l/2;i++){
		if(d[i]!=d[i+l/2]){
			ans++;
		} 
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
