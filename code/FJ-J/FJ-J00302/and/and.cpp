#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<long long>jinums;
vector<long long>ounums;
vector<long long>nums;
bool cmp(int a,int b){
	return a>b;
}
int check(int a,int b){
	if(a%2==1&&b%2==1){
		return a>b?b:a;
	}
	else if(a%2==1&&b%2==0&&b%a!=0){
		return b;
	}
	else if(a%2==0&&b%2==1&&a%b!=0){
		return a;
	}
	else if(a%2==0&&b%2==0){
		return a>b?a:b;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int num = 0;
	for(int i =0;i<n;i++){
		cin>>num;
		nums.push_back(num);
		if(num%2==0){
			ounums.push_back(num);
		}
		else{
			jinums.push_back(num);
		}
	}
	sort(jinums.begin(),jinums.end(),cmp);
	sort(ounums.begin(),ounums.end(),cmp);
	sort(nums.begin(),nums.end(),cmp);
	//使奇偶数列从大到小排
	int l = 0,j=0,f=0,sum=nums[0];
	for(int i =0;i<m;i++){
		if(sum%2==1){
			sum=nums[f];
			l++;
			
		}
		else {
			if(j<ounums.size())
			sum=ounums[j];
			else if(l<jinums.size()){
				sum=jinums[l];
			}
			else sum=nums[f];
			j++;
		}
		f++;
	}
	cout<<sum;
}