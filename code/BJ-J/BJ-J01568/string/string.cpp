#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char b[200010];
bool flag;
int rp;
long long L;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		if(i!=0){
			if(b[i]==b[i-1]){
				rp++;
			}
		}
		L+=a[i];
	}
	if(rp==n){
		cout<<0;
		return 0;
	}
	
	int sy=0,ans=0,l=0,r=n-1;
	long long yl=0,mid=L/2;
		while(yl<=mid){
			if(a[l]+yl>=mid){
				a[l]-=-a[l]-yl+mid;
			}
			else if(a[r]+yl>=mid){
				a[r]-=-a[r]-yl+mid;
			}
			sy=a[l]-a[r];
			//判断
			if(sy>=0){
				if(b[l]!=b[r]){
					ans+=a[r];
				}
			}
			else if(sy<0){
				if(b[l]!=b[r]){
					ans+=a[l];
				}
			}
			//准备下一次循环
			if(sy>0){
				a[l]-=a[r];
				r--;
				yl+=a[r];
			}
			else if(sy==0){
				l++;
				r--;
				yl+=a[l];
			}
			else{
				a[r]-=a[l];
				l++;
				yl+=a[l];
			}
		}
			cout<<ans;
	return 0;
}
