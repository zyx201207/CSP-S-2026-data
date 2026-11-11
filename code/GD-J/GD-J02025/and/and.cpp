#include<bits/stdc++.h> 
using namespace std;

int n,m,a[1000000],cnt,sum=INT_MIN,q[100000],k;

void fun(int pos){
	if(pos>m){
		sum=max(sum,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(q[i]==1) continue;
		k=cnt;
		cnt=cnt&a[i];
		q[i]=1;
		fun(pos+1);
		q[i]=0;
		cnt=k;
	}
	return ;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=a[i];
		k=a[i];
		q[i]=1;
		fun(2);
	}
	cout<<sum;
	return 0;
} 
