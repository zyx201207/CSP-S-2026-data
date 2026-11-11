#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n>>m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int k=a[i]-a[j];
			if(k>=0){
				b[i]+=k;
			}
		}
	}
	for(int i=n-1;i>=-1;i--){
		cout << b[i] <<endl;
		if(b[i]<m){
			cout << i;
			break; 
		}
		else if(i==0){
			cout << 0;
			break;
		}
	}
	return 0;
} 
