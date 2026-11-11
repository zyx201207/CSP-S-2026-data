#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void dyr(){
	int n,lk=1,rk=0;
	ll ans=0;
	cin>>n;
	vector<int> a(n+1);
	vector<char> b(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		rk+=a[i];
	}for(int l=1,r=n;l<r;){
		if(a[l]>a[r]){
			if(b[l]!=b[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}else{
			if(b[l]!=b[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}
	}cout<<ans;
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	dyr();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
