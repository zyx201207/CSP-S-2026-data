#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[100000]={ },b[1000000]={ };
	long long n,sum=0;
	cin>>n;
	int m=0;
	for(int i=1;i<=n;i++){
		int ans;
		char a1;
		cin>>ans>>a1;
		for(int j=0+m;j<0+m+ans;j++){
				a[j]=a1;
			}
			m+=ans;
		}
	int ans=0;
	for(int i=m-1;i>=0;i--){
		b[ans]=a[i];
		ans++;
	}
	for(int i=0;i<=m/2;i++){
		if(a[i]!=b[i]) sum++;
	}
	cout<<sum;
	return 0;
} 
