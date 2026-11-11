#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans[100005],num[10005];
int cha[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int flag=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]!=a[j]){
				flag=1;
			}
		}
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			ans[i]=ans[i]+(a[i]-a[j]);
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]) sum+=1;
		}
	}
	for(int i=0;i<n;i++){
		num[i]=m-ans[i];
	}
	sort(num,num+n);
	for(int i=0;i<n;i++){
		if((m-ans[i])==num[0]){
			cout<<i+sum-1;
			return 0;
		}
	}
	return 0;
}
