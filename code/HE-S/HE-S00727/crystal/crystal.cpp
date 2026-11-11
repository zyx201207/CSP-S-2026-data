#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,maxn=-1000000000000,minn=1000000000000,a[250008];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a,a+n);
	
	//Ãÿ≈–A+Ãÿ≈–B
	long long ss=a[1]-a[0],f=0;
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=ss){
			f=1;
			break;
		}
	}
	if(f==0){
		for(int i=1;i<n;i++){
			int x=(1+i)*ss*i/2;
			if(x>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	
	//∆’±È”√¿˝ 
	for(long long k=maxn;k>=minn;k--){
		long long mm=m,i=n-1,num=0;
		while(mm&&i>=0){
			if(a[i]<=k){
				if(mm<k-a[i]){
					break;
				}
				else{
					//cout<<i<<" ";
					mm-=k-a[i];
					num++;
					i--;
				}
			}
			else{
				i--;
			}
		}
		//cout<<num<<endl;
		sum=max(sum,num);
	}
	cout<<sum;
	return 0;
} 
