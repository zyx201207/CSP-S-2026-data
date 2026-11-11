#include <bits/stdc++.h>
using namespace std;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long count;
	long long a[200010];
	long long sum=0;
	long long k=0;
	int m=1;
	cin>>n;
	int w=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
	} 
	if(n==1){
		cout<<0;
		return 0;
	}
	k=a[m];
	while(m<w){
		if(k>a[w]and s[m]!=s[w]){
		count=a[w];
		k=k-a[w];
		sum+=count;
		w--;
		}
		if(k<a[m]and s[m]!=s[w]){
		count=a[m];
		sum+=k-a[w];
		m++;
	}
	}
	
	cout<<sum;
	
	return 0;
}
