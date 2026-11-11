#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=j;){
		if(a[i]<a[j]){
			if(c[i]!=c[j])sum+=a[i];
			a[j]-=a[i];
			i++;
		}
		else{
			if(c[i]!=c[j])sum+=a[j];
			a[i]-=a[j];
			j--; 
		}
	}
	cout<<sum;
}
/*
6
5000 a
10000 b
5000 a
10000 b
5000 a
10000 b
*/
