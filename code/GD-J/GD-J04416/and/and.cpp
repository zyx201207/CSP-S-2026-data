#include<fstream>
#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,in[200001];
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>in[i];
	}
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(in[j]<in[i]){
				swap(in[j],in[i]);
			}
		}
	}
	int mans = 0;
	int a[200001];
	while(1){
		int j = 0;
		for(int i = 0;i<n-1;i++){
			if(a[i] >= n){
				a[i+1] += 1;
				a[i] = 0;
			}
		}
		if(a[m-1] == n-1)break;
		bool f = 0;
		if(f){
			continue;
		}
		int ans = in[a[0]];
		for(int i = 1;i<m;i++){
			if(a[i-1]==a[i+1]){
				ans = 0;
				break;
			}
			ans = ans&in[a[i]];
		}
		if(mans<ans){
			mans = ans;
		}
		a[0]+=1;
	}
	cout<<mans;
}
