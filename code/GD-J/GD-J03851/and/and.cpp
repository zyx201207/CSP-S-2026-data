#include <bits/stdc++.h>
using namespace std;
int n,m;
long long nums[100005];
long long a;
int cnt,result_cnt,result_digit;
int l=0,r=30;
int mid=15;
long long final_result;
bool bigger(long long a,long long b){
	return a>b;
}
long long pow_two(int pow){
	int n=pow;
	long long base=2;
	long long num=1;
	while(n>0){
		if(n%2==1){
			num*=base;
		}
		base*=base;
		n/=2;
	}
	return num;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	while(n>m){
		while(l<r){
			a=pow_two(mid);
			cnt=0;
			for(int i=0;i<n;i++){
				if(nums[i]&a==a){
					cnt++;
				}
			}
			if(cnt<m){
				r=mid-1;
			}else{
				l=mid;
			}
			mid=(l+r+1)/2;
		}
		result_digit=mid;
		a=pow_two(result_digit);
		result_cnt=0;
		for(int i=0;i<n;i++){
			if(nums[n]&a!=a){
				nums[i]=0;
				result_cnt++;
			}
		}
		sort(nums,nums+n,bigger);
		n-=result_cnt;
		l=0;
		r=result_digit-1;
	}
	final_result=nums[0];
	for(int i=1;i<n;i++){
		final_result=final_result&nums[i];
	}
	cout<<final_result;
	return 0;
}

