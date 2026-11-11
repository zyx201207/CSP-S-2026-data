#include <bits/stdc++.h>
using namespace std;
int n,ns[200005];long long summ=0;char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ns[i]>>s[i];
	}
	int i=1,j=n;
	while (i<=n&&j>=1&&i<j){
		if (ns[i]==0&&ns[j]==0){
			break;
		}
		int ndx=min(ns[i],ns[j]);
		if (s[i]!=s[j]){
			summ+=ndx;
		}
		if (ns[i]==ndx) i++;
		else ns[i]-=ndx;
		if (ns[j]==ndx) j--;
		else ns[j]-=ndx;
	}
	cout<<summ<<endl;
	return 0;
} 
