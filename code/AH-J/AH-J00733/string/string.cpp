#include<bits/stdc++.h>
using namespace std;
int a[200100];
char c[200100],s[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=1;
	double cnt=0,sum=0;
	cin>> n;
	for(int i=1;i<=n;i++){
		cin>> a[i] >> c[i];
		sum+=a[i];
	}
	if(n==1){
		cout<< 0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[k]=c[i];
			k++;
		}
	}
	for(int i=1;i<=ceil(sum/2);i++){
		if(s[i]!=s[n+1-i]) cnt++;
	}
	cout<< cnt;
	return 0;
}
