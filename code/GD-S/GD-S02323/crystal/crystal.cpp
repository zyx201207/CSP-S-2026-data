#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,m2,s=0,s2=0;
	cin>>n>>m;
	m2=m;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n);
	for(int j = n-1;j>0;j--){
		for(int k = 1;k<n-j+1;k++){
			if (m2>=a[j]-a[j-k]){
				s++;
				m2-=(a[j]-a[j-k]);
			}
			else{
				break;
			}
		}
		m2=m;
		s2=max(s,s2);
		s=0;
	}
	cout<<s2;
	return 0;
}
