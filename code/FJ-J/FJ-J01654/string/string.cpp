#include<bits/stdc++.h>
using namespace std;
long long cnt,n,x[200006];
char y[200006];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	long long l=1,r=n;
	while(l<=r){
		if(y[l]==y[r]){
			if(x[l]>x[r]){
				x[l]-=x[r];
				r--;
			}else{
				x[r]-=x[l];
				if(x[r]==0)r--;
				l++;
			}
		}else{
			if(x[l]>x[r]){
				cnt+=x[r];
				x[l]-=x[r];
				r--;
			}
			else{
				x[r]-=x[l];
				if(x[r]==0)r--;
				cnt+=x[l];
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
