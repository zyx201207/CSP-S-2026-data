#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;cin>>n;char b;
	long long ans=0,s=0;
	int x[n+1][2]={};
	for(int i=0;i<n;i++){
		cin>>a>>b;
		s+=a;
		x[i][0]=a,x[i][1]=int(b);
	}
	if(s%2!=0 || n%2!=0){
		int c=0,i=0;
		while(c>=s/2){
			c+=x[i][0];
			i++;
		}
		for(int j=n;j>i;j--) x[j][0]=x[j-1][0],x[j][1]=x[j-1][1];
		x[i+1][0]=x[i][0]-s/2+c,x[i+1][1]=x[i][1];
		x[i][0]=((s/2-c)%2==0 ? s/2-c : s/2-c-1);
	}
	int l=0,r=(s%2!=0||n%2!=0 ? n : n-1);
	while(l<r){
		if(x[l][1]!=x[r][1]){
			if(x[l][0]>x[r][0]){
				x[l][0]-=x[r][0];
				ans+=x[r][0];
				x[r][0]=0;
				r--;
			}else if(x[l][0]<x[r][0]){
				x[r][0]-=x[l][0];
				ans+=x[l][0];
				x[l][0]=0;
				l++;
			}else{
				ans+=x[l][0];
				x[l][0]=0,x[r][0]=0;
				r--;l++;
			}
		}else{
			if(x[l][0]>x[r][0]){
				x[l][0]-=x[r][0];
				x[r][0]=0;
				r--;
			}else if(x[l][0]<x[r][0]){
				x[r][0]-=x[l][0];
				x[l][0]=0;
				l++;
			}else{
				x[l][0]=0,x[r][0]=0;
				r--;l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
