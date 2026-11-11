#include<bits/stdc++.h>
using namespace std;
	unsigned long long m,sum;
int a[5000200];
int cho(int dys){
	sum=0;
	for(int i=dys;i>=0;i--){
		sum+=a[dys]-a[i];
	}
	if(sum<=m) return 1;
	else return 0;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int num=0;
	while(cho(num)) num++;
	cout<<num;
} 
