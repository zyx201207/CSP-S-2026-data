#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100000005];
char b[100000005];
long long ans=0;
long long cnt=0;
char c[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>a[i]>>b[i];
	cnt+=a[i];
	for(int j=cnt-a[i];j<cnt;j++)c[j]=b[i];
}	
for(int i=0;i<cnt;i++){
	int j=cnt-i-1;
	if(i==j||i==j+1){
	break;
}

	if(c[i]!=c[j])ans++;
	
}
cout<<ans;

	return 0;
}

