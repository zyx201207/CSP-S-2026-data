#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int n;
int num[N];
long long ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(num[l]==num[r]){
			if(c[l]!=c[r]){
				ans+=num[l];
			}
			l++,r--;
		}
		else{
			if(num[l]>num[r]){
				if(c[l]!=c[r]){
					ans+=num[r];
				}
				num[l]-=num[r];
				r--;
			}
			else if(num[l]<num[r]){
				if(c[l]!=c[r]){
					ans+=num[l];
				}
				num[r]-=num[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
