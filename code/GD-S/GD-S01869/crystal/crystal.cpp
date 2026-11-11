#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

int a[N];
int n,m;

int ans=-1;
int diff[N];


void ff(int M){
	int num=0;
	for(int i=n;i>1;i--){
		for(int j=i-1;j>0;j--){
			if(diff[i]!=0||M==0||a[i]-M>a[j])return ;
			
			if(M-a[i]+a[j]>0){
				num++;
				ff(M-a[i]+a[j]);
			}
		}diff[i]=num;
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[n];
	}
	a[0]=-1*N;
	sort(a+1,a+n+1);
	
	int mm=0,c=1;
	for(int i=1;i<=n;i++){
		//cout<<a[i]<<' ';
		if(a[i+1]==a[i]){
			c++;
		}else {
			mm=max(c,mm);
			c=1;
		}
	}
	if(m==0){
		cout<<mm;
		return 0;
	}
	else {
		ff(m);
	}
	
	for(int i=1;i<=n;i++){
		ans=max(ans,diff[i]);
	}cout<<ans;
	
	return 0;
	
}
