#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,l=0,r,sum=0;
	cin>>n;
	int p[200005];
	char c[200005];
	int x=n;
	for(int i=0;i<n;i++){
		cin>>p[i]>>c[i];
	}
	r=n-1;
	int t;
	while(x>0){
		t=min(p[l],p[r]);
		if(c[l]!=c[r]) sum+=t;
		p[l]-=t;
		p[r]-=t;
		if(p[l]==0){
			x--;
			l++;
		}
		if(p[r]==0){
			x--;
			r--;
		}
	}
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
