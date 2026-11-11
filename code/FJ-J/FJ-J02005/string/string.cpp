#include<bits/stdc++.h>
using namespace std;
long long n;
int a[200005];
char ch[200005];
long long cnt;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
	}
	
	
	
	int l=1;int r=n; 
	while(l<=r){
		if(a[l]==a[r]&&ch[l]==ch[r]){
			l++;
			r--;
			continue;
		}
		if(a[l]==a[r]&&ch[l]!=ch[r]){
			cnt+=a[l];
			l++;
			r--;
			continue;
		}
		if(a[l]>a[r]&&ch[l]!=ch[r]){
			cnt+=a[r];
			a[l]-=a[r];
			r--;
			continue;
		}
		if(a[l]<a[r]&&ch[l]!=ch[r]){
			cnt+=a[l];
			a[r]-=a[l];
			l++;
			continue;
		}
		if(a[l]<a[r]&&ch[l]==ch[r]){
			
			a[r]-=a[l];
			l++;
			continue;
		}
	if(a[l]>a[r]&&ch[l]==ch[r]){
			
			a[l]-=a[r];
			r--;
			continue;
		}
	
	
	
	}	
	
	
	
	cout<<cnt;
	
	
	return 0;
}
