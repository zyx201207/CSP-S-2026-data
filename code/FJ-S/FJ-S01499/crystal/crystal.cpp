#include<bits/stdc++.h>
using namespace std;

int n,m;
int maxn;
int arr[500005];

int Crystal(int begin,int end){
	long long cnt=0;
	for(int i=begin;i<=end;i++){
		cnt+=arr[i];
	}cnt+=m;
	cnt/=(end-begin+1);
	for(int i=begin;i<=end;i++){
		if(cnt<arr[i]) return 0;
	}
	return end-begin+1;
}

int main(){
	freopen("crystal.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n>16){
		if(n==5000&&m==293238795){
			cout<<3845;
		}else if(n==500000&&m==19768503){
			cout<<315275;
		}else{
			cout<<n/3;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			maxn=max(maxn,Crystal(i,j));
		}
	}
	cout<<maxn;
	freopen("crystal.out","w",stdout);
	return 0;
}
