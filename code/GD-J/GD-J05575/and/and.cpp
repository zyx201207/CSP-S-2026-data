#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,an;
	cin>>n>>an;
	int num[n+1];
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num+0,num+n);
	int ans=num[n-1];
	for(int i=1;i<an;i++){
		ans=ans&num[n-i-1];
	}
	cout<<ans;
	return 0;
}
