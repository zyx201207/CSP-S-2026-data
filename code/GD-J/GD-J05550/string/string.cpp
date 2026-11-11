#include<bits/stdc++.h>
using namespace std;
int num[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int n,k;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i]>>s[i];
		k+=num[i];
	}
	
	long long l=0,r=n-1,e=0;
	
	while(l<r){
		if(s[l]==s[r]){
			if(num[l]==num[r]){
				l++,r--;
			}
			else if(num[l]<num[r]){
				num[r]-=num[l];
				l++;
			}
			else{
				num[l]-=num[r];
				r--;
			}
		}
		else{
			if(num[l]==num[r]){
				e+=num[l];
				l++,r--;
			}
			else if(num[l]<num[r]){
				e+=num[l];
				num[r]-=num[l];
				l++;
			}
			else{
				e+=num[r];
				num[l]-=num[r];
				r--;
			}
		}
	}
	cout<<e;
	
	return 0;
}
