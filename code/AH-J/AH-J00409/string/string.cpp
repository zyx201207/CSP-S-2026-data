#include<bits/stdc++.h>
using namespace std;
int n,a[200005],cnt;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
