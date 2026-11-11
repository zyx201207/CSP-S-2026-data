#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+10;
long long a[N],s[N];
int n;long long m;
bool check(long long len){
	for(int i=len;i<=n;i++){
		if(m>=a[i]*len-(s[i]-s[i-len])){
			return true;
		}
	}return false;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=1e12;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long l=1,r=n,mid;
	while(l<r){
		mid=l+r>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

