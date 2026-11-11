#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int d[a],sum[1000000];
	for(int i=0;i<a;i++){
		cin>>d[i];
	}
	int num=0;
	for(int i=0;i<a;i++){
		for(int j=i+1;j<a;j++){
			sum[num]=(d[i]&d[j]);
		}
	}
	cout<<*max_element(sum,sum+1000000);
	return 0;
} 
