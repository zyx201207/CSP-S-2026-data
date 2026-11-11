#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],cnt;
char b[200010];
void solve(){
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(b[l]!=b[r]){
			if(a[l]>a[r]){
				cnt+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				cnt+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				cnt+=a[l]; 
				l++,r--;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				l++,r--;
			}
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}
