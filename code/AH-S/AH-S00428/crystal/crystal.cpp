#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int stone[500003];
bool check(int id){
	long long num=stone[id]*id;
	for(int i=1;i<=id;i++){
		num-=stone[i];
	}
	if(num<=m)return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>stone[i];
	}
	if(m<=1e9){
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid)){
				l=mid+1;
			}else{
				r=mid;
			}
		}
		for(int i=1;i<=n;i++){
			if(stone[i]!=stone[l-1]&&stone[i-1]==stone[l-1]){
				cout<<i-1;
				exit(0);
			}
		}
	}else{
		if(stone[1]==stone[2])cout<<n;
		if(stone[2]-stone[1]==stone[3]-stone[2]){
			int d=stone[2]-stone[1];
			int i;
			for(i=0;pow(2,i)*d<=m;i++)
			cout<<i+1;
		}
	}
	return 0;
}
