#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int num[200100];
char s[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>s[i];
	}
	int l=1,r=n;
	while(l<r){
		if(s[l]-'0'==s[r]-'0'){
			if(num[l]>num[r]){
				num[l]-=num[r];
				num[r]=0;
				r--;
			}
			else if(num[r]>num[l]){
				num[r]-=num[l];
				num[l]=0;
				l++;
			}
			else{
				num[l]=0;
				num[r]=0;
				r--;
				l++;
			}
		}
		else{
			if(num[l]>num[r]){
				num[l]-=num[r];
				ans+=num[r]; 
				num[r]=0;
				r--;
			}
			else if(num[r]>num[l]){
				num[r]-=num[l];
				ans+=num[l];
				num[l]=0;
				l++;
			}
			else{
				ans+=num[l];
				num[l]=0;
				num[r]=0;
				
				r--;
				l++;
			}
		}
	}
	cout<<ans;
}

