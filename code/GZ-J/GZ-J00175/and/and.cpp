#include<bits/stdc++.h>
using namespace std;
int m,n;
long long a[100003];
int c(int x){
	int max=0;
	for(int i=0;i<n;i++){
		if((c[i] and i)>max){
			max=c[i] and i;
		}
	}
	return max;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		long long p;
		cin>>p;
		a[i]=p;
	}
	cout<<c[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
