#include<bits/stdc++.h>
using namespace std;

long long n,x;
long long a[200005];
char c;
string s="";

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	long long l=0,ans=0;
	for(int i=0;i<n;i++){
		cin>>x>>c;
		a[i]=x;
		s+=c;
	}
	
	long long left=0,right=n-1;
	while(left<right){
		if(s[left]==s[right]){
			if(a[left]<a[right]){
				a[right]-=a[left];
				left++;	
			}else if(a[left]>a[right]){
				a[left]-=a[right];
				right--;
			}else{
				left++;
				right--;
			}
		}else{
			if(a[left]<a[right]){
				ans+=a[left];
				a[right]-=a[left];
				left++;	
			}else if(a[left]>a[right]){
				ans+=a[right];
				a[left]-=a[right];
				right--;
			}else{
				ans+=a[left];
				left++;
				right--;
			}
		}
	}
	cout<<ans;
	
	return 0;
	
} 
