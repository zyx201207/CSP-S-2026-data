#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+50;
long long n,sum=0;
long long l,r;
long long a[N],b[N];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		b[i]=c-'a'+1;
	}
	while(l<=r){
		if(b[l]==b[r]){
			if(a[l]==a[r]){
				l++;
				r--;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}else{
			sum+=min(a[l],a[r]);
			if(a[l]==a[r]){
				l++;
				r--;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<sum;
	return 0;
}
