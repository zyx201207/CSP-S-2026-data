#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200001];
char b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int aa;
		char c;
		cin>>aa>>c;
		a[i]=aa;
		b[i]=c;
	}
	long long l=1,r=n,cnt=0;
	while(l<=r){
		long long mm=min(a[l],a[r]);
		if(b[l]!=b[r]){
			cnt+=mm;
		}
		a[l]-=mm;
		a[r]-=mm;
		if(a[l]==0){
			l+=1; 
		}
		if(a[r]==0){
			r-=1;
		}
	}
	cout<<cnt;
	//cout<<s;
	//cin.tie(0);
	//cout.tie(0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

