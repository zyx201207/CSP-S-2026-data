#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int p,s;
	cin>>p>>s;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+p,greater<int>());
	int sum=a[1];
	for(int i=2;i<=s;i++){
		sum&=a[i];
		
	}
	cout<<sum;
//	cout<<(32&31);
//	cout<<"\n"<<(32&31&7);
	
	return 0;
} 
