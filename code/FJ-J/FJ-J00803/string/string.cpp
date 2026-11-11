#include<bits/stdc++.h>
using namespace std;
unsigned long long n,x[200005];
char c[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
	}
	unsigned long long z=0;
	for(int i=1,j=n;i<=j;){
		if(c[i]!=c[j]){
			z+=min(x[i],x[j]);
		}
		if(x[i]<=x[j]){
			x[j]-=x[i];
			i++;
		} 
		if(x[i]>=x[j]){
			x[i]-=x[j];
			j--;
	    }
	}
	cout<<z;
	return 0;
}
