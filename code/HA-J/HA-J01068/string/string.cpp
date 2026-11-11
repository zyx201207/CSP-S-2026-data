#include<bits/stdc++.h>
using namespace std;
struct node{
	long long zhi;
	char strs;
}ans[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a=0,n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ans[i].zhi>>ans[i].strs;
	}
	long long left=0,right=n-1;
	while(left<right){
		while(ans[left].zhi<ans[right].zhi){
			if(ans[left].strs!=ans[right].strs) a+=ans[left].zhi;
			ans[right].zhi-=ans[left].zhi;
			left++;
		}
		while(ans[right].zhi<ans[left].zhi){
			if(ans[right].strs!=ans[left].strs) a+=ans[right].zhi;
			ans[left].zhi-=ans[right].zhi;
			right--;
		}
		if(ans[left].zhi==ans[right].zhi){
			if(ans[left].strs!=ans[right].strs) a+=ans[left].zhi;
			left++;
			right--;
		}
	}
	cout<<a;
	return 0;
}
