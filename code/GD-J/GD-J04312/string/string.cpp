#include<bits/stdc++.h>
using namespace std;
int n;
char c[200001];
long long s,a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int j=n;
	for(int i=1;i<=n;i++){
		if(j==i)break;
		while(j!=i&&a[j]<=a[i]){
			a[i]-=a[j];
			if(c[i]!=c[j])s+=a[j];
			a[j]=0;
			j--;
		}
		a[j]-=a[i];
		if(c[i]!=c[j])s+=a[i];
		a[i]=0;
	}
	cout<<s;
	return 0;
}
