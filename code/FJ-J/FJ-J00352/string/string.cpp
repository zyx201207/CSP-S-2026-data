#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long a[200010],l,r,len;
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	l=1;
	r=n;
	while(l<r){
		while(a[l]>=a[r]&&l<r){
			if(b[l]==b[r]){
				a[l]-=a[r];
				--r;
			}else{
				a[l]-=a[r];
				len+=a[r];
				--r;
			}
		}
		while(a[l]<=a[r]&&l<r){
			if(b[l]==b[r]){
				a[r]-=a[l];
				++l;
			}else{
				a[r]-=a[l];
				len+=a[l];
				++l;
			}
		}
	}
	cout<<len<<endl;
	return 0;
}

