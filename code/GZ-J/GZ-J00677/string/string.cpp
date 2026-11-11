//GZ-J00677 遵义市第十九中学 李俊希 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[200010],n,x,li=0,lock=0;
	char y;
	string s="";
	cin>>n;
	int left=0,right=n-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>y;
		s=s+y;
	}
	while(left<right){
		if(s[left]==s[right]){
			if(a[left]==a[right]){
				lock=1;
				left++;
				right--;
			}
			if(a[left]>a[right] && lock==0){
				lock=1;
				a[left]=a[left]-a[right];
				right--;
			}
			if(a[left]<a[right] && lock==0){
				a[right]=a[right]-a[left];
				left++;
			}
		}
		lock=0;
		if(s[left]!=s[right]){
			if(a[left]==a[right]){
				li=a[left]+li;
				lock=1;
				left++;
				right--;
			}
			if(a[left]>a[right] && lock==0){
				lock=1;
				a[left]=a[left]-a[right];
				li=a[right]+li;
				right--;
			}
			if(a[left]<a[right] && lock==0){
				a[right]=a[right]-a[left];
				li=a[left]+li;
				left++;
			}
		}
		lock=0;
	}
	cout<<li;
	
	return 0;
}
