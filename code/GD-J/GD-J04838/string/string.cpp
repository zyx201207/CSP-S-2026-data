#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long m[n];
	char s[n];
	for(int i=0;i<n;i++){
		cin>>m[i]>>s[i];
	}
	int left=0,right=n-1;
	long long sum=0;
	while(right!=left&&left<right){
		int minn=min(m[right],m[left]);
		if(s[right]!=s[left]){
			sum+=minn;
		}
		m[right]-=minn;
		m[left]-=minn;
		if(m[left]==0)left++;
		if(m[right]==0)right--;
	}
	cout<<sum;
	return 0;
}
