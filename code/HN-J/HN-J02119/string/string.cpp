#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	long long lens=s.size();
	int r=0,l=lens-1;
	while(r!=l){
		if(s[r]!=s[l]){
			s[l]=s[r];
			ans++;
		}
		r++;
		l--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

