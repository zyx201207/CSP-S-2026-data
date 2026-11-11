#include<bits/stdc++.h>
using namespace std;
char a[200005];
long long n,m[200005],ans=0,num=0,zh=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i]>>a[i];
		num+=m[i];
	}
	int l=0,r=n-1,j;
	while(l<r){
		j=min(m[l],m[r]);
		if(a[l]!=a[r]) ans+=j;
		if(m[l]<m[r]){
				l++;
				m[r]-=j;	
		}
		else if(m[l]==a[r]){
				l++,r--;
		}
		else{
				r--;
				m[l]-=j;
		}
	}
	cout<<ans;
	return 0;
}

