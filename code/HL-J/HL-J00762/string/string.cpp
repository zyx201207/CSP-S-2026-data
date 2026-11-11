#include<bits/stdc++.h>

using namespace std;

long long n,ans;
long long a[200005];
char c[200005];
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	
	int l=1,r=n;
	while(l<r){
		int x=a[l]<a[r]?a[l]:a[r];
		if(c[l]==c[r]){
			a[l]-=x;
			a[r]-=x;
			if(a[l]>a[r]) r--;
			else l++;
		}else{
			ans+=x;
			a[l]-=x;
			a[r]-=x;
		}
		while(a[l]==0)l++;
		while(a[r]==0)r--; 
	}
	
	cout<<ans;
	
	return 0;
}