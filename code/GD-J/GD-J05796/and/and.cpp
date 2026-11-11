#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[100000000];
int mum[1000000];
int mx=0;
int u=0;
int circle(int s){
	int h=s-1;
	for(int i=1;i<=n;i++){
		int cnt=1;
		for(int j=0;j<m;j++){
			if(i==mum[j]){
				cnt=0;
				break;
			}
		}
		if(cnt==0){
			continue;
		}
		mum[m-s]=i;
		if(h==0){
			u=num[mum[0]];
			for(int j=1;j<m;j++){
				u=u&num[mum[j]];
			}
			mx=max(mx,u);
			if(i=n){
				return mx;
			}
			continue;
		}
		circle(h);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	circle(m);
	cout<<mx;
	return 0;
}
