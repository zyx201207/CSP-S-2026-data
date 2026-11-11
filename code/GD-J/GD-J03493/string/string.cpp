#include<iostream>
#include<string>
using namespace std;
long long ans=0,n,a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int l=1,r=n;
	while(l<r){
		if(s[l]==s[r]){
			if(a[l]>a[r]){a[l]-=a[r];r--;}
			else if(a[l]<a[r]){a[r]-=a[l];l++;}
			else {l++;r--;}
		}
		else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else {
				ans+=a[l];
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
