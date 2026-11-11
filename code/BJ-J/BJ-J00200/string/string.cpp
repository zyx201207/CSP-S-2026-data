#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	int n;
	cin>>n;
	char s[100005];
	long long t[100005];
	long long len=0;
	char f[200005];
	for(int i=1;i<=n;i++){
		cin>>t[i]>>s[i];
		for(int j=1;j<=t[i];j++){
			f[len+j]=s[i];
		}
		len+=t[i];
	}
	int sum=0;
	int l=1,r=len;
	while(l<=r){
		if(f[l]!=f[r]) sum++;
		l++;
		r--;
	}
	cout<<sum<<endl;
	return 0;
}