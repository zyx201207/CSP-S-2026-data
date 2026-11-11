#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];char c[200005];
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		int now_int1=a[l];
		int now_int2=a[r];
		if(c[l]!=c[r]){		
			cnt+=min(now_int1,now_int2);
			if(now_int1>now_int2){
				a[l]-=now_int2;
				r--;
			}
			else if(now_int1<now_int2){
				a[r]-=now_int1;
				l++;
			}
			else{
				l++;r--;
			}
		}
		else{
			l++;r--;
		}
	}
	cout<<cnt;
	return 0;
}

