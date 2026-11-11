#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int sum=0,change=0;
	int n;
	int a[200005];
	string c,s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int w=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			w++;
			s[w]=c[i];
		}
	}
	for(int i=1;i<=sum/2;i++){
		int x=sum-i+1;
		if(s[i]!=s[x])change++;
	}
	cout<<change;
	
	
	
	
	return 0;
}
