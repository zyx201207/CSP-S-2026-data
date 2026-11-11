#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,a[200010],ans;
char b[200010];
int main(){
	freopen("string.in" , "r" , stdin );
	freopen("string.out" , "w" , stdout );
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cnt++;
		cin>>a[cnt]>>b[cnt];
		if(b[cnt]==b[cnt-1]){
			a[cnt-1]+=a[cnt];
			cnt--;
		}
	}
	for(int i=1;i<=cnt;i++){
		m+=a[i];
	}
	long long l=1,r=cnt;
	while(l<r){
		if(a[l]==a[r]){
			if(b[l]==b[r]){
				l++;
				r--;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}else if(a[l]>a[r]){
			if(b[l]==b[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
		}else if(a[l]<a[r]){
			if(b[l]==b[r]){
				a[r]-=a[l];
				l++;
			}else{
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
