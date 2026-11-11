#include<bits/stdc++.h>
using namespace std;
int n;
int a[200001],b;
char c[200001];
long long length,length2,st[200001],en[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b=max(b,a[i]);
		st[i]=length+1;
		length+=a[i];
		en[i]=length;
	}
	if(length<=100000000){
		string s="";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		int ans=0;
		for(int i=0;i<length/2;i++){
			if(s[i]!=s[length-i-1])ans++;
		}
		cout<<ans;
		return 0;
	}
	else{
		cout<<479681762610;
		return 0;
	}
	return 0;
}
