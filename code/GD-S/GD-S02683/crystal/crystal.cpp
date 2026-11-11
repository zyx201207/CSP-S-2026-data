#include<bits/stdc++.h>
using namespace std;
long long a[5555555],b[5555555];
long long m;
int sum = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	b[0]=0;
	sort(a,a+n);
	for(int i =1;i<n;i++){
		b[i] = a[i]-a[i-1]+b[i-1];
	}
	for(int r = 0;r<n;r++){
		int count = 0;
		int s = m;
		for(int l = r;l>=0;l--){
			s = s+b[l]-b[r];
			if(s>=0){
				count++;
				continue;
			}
			break;
		}
		sum = max(sum,count);
	}
	cout << sum;
} 
