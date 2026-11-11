#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	while(r>l){
		if(a[l]>a[r]){
			if(s[l]==s[r]){
				a[l]-=a[r];
				r--;
			}else{
				k+=a[r];
				a[l]-=a[r];
				r--;
			}
		}else if(a[l]<a[r]){
			if(s[l]==s[r]){
				a[r]-=a[l];
				l++;
			}else{
				k+=a[l];
				a[r]-=a[l];
				l++;
			}
		}else{
			if(s[l]==s[r]){
				l++,r--;
			}else{
				k+=a[l];
				l++,r--;
			}
		}
	}
	cout<<k<<endl;
	return 0;
}
