#include<bits/stdc++.h>
using namespace std;
long long a[1000000],n,m=0;
char b[1000000];
int f=0;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	scanf("%ld%s",&a[1],&b[1]);
	for(int i=2;i<=n;i++){
		scanf(" %ld%s",&a[i],&b[i]);
		if(b[1]!=b[i]) f=1;
		m+=a[i];
	}
	int max=-1;
	for(int i=1;i<=n;i++){
		if(max<a[i]) max=a[i];
	}
	if(m%2==0){
		cout<<m-max;
	}else{
		cout<<m-max-1;
	}
	
	return 0;
}
