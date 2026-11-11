#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	long long sum=0;
	while(i<j){
		int m=min(a[i],a[j]);
		a[i]-=m;
		a[j]-=m;
		if(c[i]!=c[j]){
			sum+=m;
		}
		if(a[i]<=0){
			i++;
		}
		if(a[j]<=0){
			j--;
		}
	}
	cout<<sum;
	return 0;
} 
