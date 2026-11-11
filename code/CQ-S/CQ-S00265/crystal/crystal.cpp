#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,flag;
long long m,a[1000001],s;
int maxn;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			s=a[i]-a[i-1];
		}
		if(a[i]-a[i-1]!=s&&i>1){
			flag=1;
		}
	}
	if(flag==0){
		int i=1;
		while(i*i+i<m){
			i++;
		}
		cout<<(i-1)*(i-1)+i-1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m){
				maxn=max(maxn,i-j);
				break;
			}else if(sum==m){
				maxn=max(maxn,i-j+1);
			}
		}
		if(sum<m){
			maxn=max(maxn,i);
		}
	}
	cout<<maxn;
	return 0;
}

