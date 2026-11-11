#include<bits/stdc++.h>
using namespace std;
int z[200002];
char y[200002];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>z[i]>>y[i];
	}
	long long ans=0;
	int a=z[1], b=z[n];
	for(int i=1, j=n;i<j;){
		if(y[i]!=y[j]){
			ans+=min(a, b);
		}
		if(a==b){
			i++;
			j--;
			a=z[i];
			b=z[j];
		} else if(a<b){
			b-=a;
			i++;
			a=z[i];
		} else if(a>b){
			a-=b;
			j--;
			b=z[j];
		}
	}
	cout<<ans;
	return 0;
}
