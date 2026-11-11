#include<bits/stdc++.h>
using namespace std;
 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int num[200009]={0};
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> num[i];
	}
	sort(num+0,num+n);
	if(m==1)cout << num[n];
	int ans=num[n];
	for(int i=1;i<m;i++){
		ans=(ans&num[n-i]);
	}
	cout << ans;
	
}
