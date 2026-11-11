#include<bits/stdc++.h>
using namespace std;
const int MAXN=200010;
int n;
char c[MAXN];
int a[MAXN];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	
	int left=0,right=n-1;
	
	while(left<right){
		
		int add;
		
		if(a[left]<a[right]){
			left++;
			add=a[left];
			a[right]-=a[left];
		}
		else if(a[left]==a[right]){
			left++;
			add=a[left];
			right--;
		}
		else{
			right--;
			add=a[right];
			a[left]-=a[right];
		}
		
		
		if(c[left]!=c[right]){
			ans+=add;
		}
		
	}
	
	cout<<ans;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
