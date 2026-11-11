#include<bits/stdc++.h>
using namespace std;
long long n,len,ans;
struct node{
	long long l,s;
	char c;
}a[200005];
int c[1000006],sum[1000006];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].c;
		//cout<<a[i].c-'a'<<" "; 
		c[len+1]+=a[i].c-'a',c[len+a[i].l+1]-=a[i].c-'a';
		len+=a[i].l;
	}
	for(int i=1;i<=len;i++){
		sum[i]=sum[i-1]+c[i];
	}
	for(int i=1,j=len;i<=j;i++,j--){
		if(sum[i]!=sum[j]) ans++;
		//cout<<sum[i]<<" "<<sum[j]<<"\n";
	}
	cout<<ans;
	return 0;
} 
