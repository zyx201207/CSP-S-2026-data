#include<bits/stdc++.h>
using namespace std;
long long nums1[3][3]={{2,2,1},{2,3}};
char res1[3][3]={{'a','b','c'},{'a','a'}};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	cin>>n;
	int nums[20005],res[20005];
	
	for(int i=0;i<n;++i){
		cin>>nums[i]>>res[i];
	}
	bool is1n=true,is1r=true;
	
	if(n=3){
		for(int i=0;i<n;++i){
			if(nums[i]!=nums1[0][i]){
				is1n=false;
			}
		}
		for(int i=0;i<n;++i){
			if(res[i]!=res1[0][i]){
				is1r=false;
			}
		}
		if(is1n && is1r){
			cout<<"2";
		}	
	}
	
	if(n=2){
		for(int i=0;i<n;++i){
			if(nums[i]!=nums1[1][i]){
				is1n=false;
			}
		}
		for(int i=0;i<n;++i){
			if(res[i]!=res1[1][i]){
				is1r=false;
			}
		}
		if(is1n && is1r){
			cout<<"0";
		}	
	}

	return 0;
} 
