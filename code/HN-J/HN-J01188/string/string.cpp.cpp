#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],num=0;
	char ch[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(ch[l]!=ch[r]){
			long long t=min(a[l],a[r]);
			if(a[l]>a[r]){
				r--;
				a[l]-=t;
			}
			else if(a[r]>a[l]){
				l++;
				a[r]-=t;
			}
			else{
				l++;
				r--;
			}
			num+=t;
		}
		else{
			long long t=abs(a[l]-a[r]);
			if(a[l]>a[r]){
				r--;
				a[l]-=t;
			}
			else if(a[r]>a[l]){
				l++;
				a[r]-=t;
			}
			else{
				l++;
				r--;
			}
		}
	}
	cout<<num;
}
