#include<iostream>
using namespace std;
int main(){
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	long long n,ans=0;
	int s[55555];
	char c[55555];
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s[i]>>c[i];
	}
	int left=s[0],right=s[n-1];
	for(int i=0;i<=n/2;++i){
		if(right==0){
			right=s[n-i-1];
		}
		if(left==0){
			left=s[i];
		}
		if(left>=right){
			left-=right;
			right=0;
			if(c[i]!=c[n-i-1]){
				ans+=right;
			}
		}
		else{
			right-=left;
			left=0;
			if(c[i]!=c[n-i-1]){
				ans+=left;
			}
		}
	}
	cout<<ans;
	return 0;
}
