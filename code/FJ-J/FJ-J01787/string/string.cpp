#include<bits/stdc++.h>
using namespace std;
int a[2000005];
char c[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	int cnt=1;
	bool same=true;
	cin>>n;
	int x;
	int mi=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		x=c[1];
		mi=min(mi,a[i]);
		if(x!=c[i]){
			same=false;
			cnt++;
		}
	}
	if(n==2){
		cout<<mi;
		exit(0);
	}
	if(same){
		cout<<0;
		exit(0);
	}
	if(cnt%2==0){
		cout<<mi*3;
	}
	else{
		cout<<mi*2;
	}
	return 0;
}
