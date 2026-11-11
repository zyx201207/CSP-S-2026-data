#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long num[300000]={};
	char st[300000]={};
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
		cin>>st[i];
	}
	long long ans=0;
	int l=0,r=n-1;
	while(l<r){
		if(num[l]>num[r]){
			if(st[l]!=st[r])ans+=num[r];
			num[l]-=num[r];
			r--;
		}else if(num[l]<num[r]){
			if(st[l]!=st[r])ans+=num[l];
			num[r]-=num[l];
			l++;
		}else if(num[l]==num[r]){
			if(st[l]!=st[r])ans+=num[l];
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
