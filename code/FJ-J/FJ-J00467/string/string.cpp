#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[10005],nb=0,l=0;
	string c[10005],s[100010],t[100010];
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s[l]=c[i];
			l++;
		}
	}
	int ll=0;
	for(int i=l-1;i>=l/2;i--){
		t[ll]=s[i];
		if(t[ll]!=s[ll]){
			nb++;
		}
		ll++;
	}
	cout<<nb;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
