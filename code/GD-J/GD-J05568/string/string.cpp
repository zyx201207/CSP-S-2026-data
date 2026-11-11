#include<bits/stdc++.h>
using namespace std;
long long m;
int n;
int a[200010];
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	int l,r;
	l=0,r=n;
	while(l<r){
		if(s[l]==s[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				l++,r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}else{
			if(a[l]>a[r]){
				m+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				m+=a[l];
				l++,r--;
			}else{
				m+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<m;
	return 0;
} 

