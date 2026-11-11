#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=-1;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	long long ans[n];
	long long num[m];
	for(long long i=0;i<n;i++){
		cin>>ans[i];
	} 
	while(m--){
		for(int i=1;i<n;i++){
			if(ans[i]!=cnt){
				num[i]=max(ans[i-1],ans[i]);
				cnt=max(ans[i-1],ans[i]);
			}
		}
	}
	cout<<cnt;
	return 0;
} 
