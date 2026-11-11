#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,c=0,a[100005],s[100005],y[100005];
	cin>>n;
	cin>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]-a[j]>=0)
				y[i]+=1;
				s[i]+=a[i]-a[j];
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]<=m)
			if(c<y[i])
				c=y[i];
	}
	cout<<c;
return 0;
}
