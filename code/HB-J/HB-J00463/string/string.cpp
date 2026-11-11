#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char s[200010];
unsigned long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		getchar();
		scanf("%c",&s[i]);
	}
	int left=0,right=n-1;
	while(left!=right){
		long long minn=min(a[left],a[right]);
		a[left]-=minn;a[right]-=minn;
		if(s[left]!=s[right]) ans+=minn;
		if(a[left]==0) left++;
		if(left==right) break;
		if(a[right]==0) right--;
	}
	cout<<ans;
	return 0;
}
