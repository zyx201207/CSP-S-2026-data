#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
char b[200005];
int cnt,k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			cnt++;
			b[cnt]=c[i];
		}
	}
	for(int i=1;i<=cnt;i++){
		if(b[i]!=b[cnt]){
			k++;
		}
		cnt--;
	}
	cout<<k;
	return 0;
} 

	


