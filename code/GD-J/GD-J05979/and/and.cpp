#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
const int M=2e5+5;
int s1[N],s2[N],s3[N];
int ncf[N];
int yu(int a,int b){
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	memset(s3,0,sizeof(s3));
	int temp=1;
	while(a!=0||b!=0){
		if(a!=0){
			s1[temp]=a%2;
			a/=2;
		}
		if(b!=0){
			s2[temp]=b%2;
			b/=2;
		}
		temp++;
	}
	int temp1=temp-1;
	for(int i=1;i<temp;i++){
		if(s1[i]==s2[i])s3[temp1]=1;
		else s3[temp1]=0;
		temp1--;
	}
	int ans=0;
	int pp=0;
	for(int i=temp-1;i>=1;i--){
		int poww=pow(2,pp);
		ans+=s3[i]*poww;
		pp++;
	}
	return ans;
}
int aa[M],anss[M];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	sort(aa+1,aa+n+1);
	if(m==1){
		cout<<aa[n]<<"\n";
		return 0;
	}
	anss[1]=yu(aa[n],aa[n-1]);
	for(int i=2;i<m;i++){
		anss[i]=yu(anss[i-1],aa[n-i]);
	}
	cout<<anss[m-1];
	return 0;
}
