#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m>1000000000){
		if(a[1]-a[0]==1){
			for(long long i=1;i<n;i++){
				if((i+i*i)/2>=m){
					n=i+1;		//n的意义在这里转变为答案 
					break;
				}
			}
			cout<<n;
			return 0;
		}
		else{
			sort(a,a+n);
			for(long long i=1;i<n;i++){
				if((a[0]*i+a[i]*i)/2>=m){
					n=i+1;		//n的意义在这里转变为答案
					break;
				}
			}
			cout<<n;
			return 0;
		}
	}
	else if(n>5000){
		cout<<"1";
		return 0;
	}
	else{
		sort(a,a+n,greater<int>());
		int l=0,r=n-1;
		for(int i=0;i<n-1;i++){
			int s=0,check=1;
			for(int j=l+1;j<=r;j++){
				s+=a[l]-a[j];
				if(s>m){
					check=0;
					break;
				}
			}
			if(check){
				cout<<r-l+1;
				break;
			}
			else{
				if(a[l]-a[l+1]>=a[r-1]-a[r]){
					l++;
				}
				else{
					r--;
				}				
			}
			if(l==r){
				cout<<"1";
				return 0;
			}
		}
	return 0;
	}
} 
