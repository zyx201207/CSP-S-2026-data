#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[1123456],ai;
char s[1123456];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long aa;
		char ss;
		cin>>aa>>ss;
		if(ss==s[ai]){
			a[ai]+=aa;
		}else{
			s[++ai]=ss;
			a[ai]=aa;
		}
	}
	if(ai==1){
		cout<<0;
		return 0; 
	}
	long long sum=0,l=1,r=n;
	char aaa;
	while(l<r){
		if(s[l]==s[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				l++;
				r--;
			}
		}else{
			sum+=min(a[l],a[r]);
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}



