#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		//zong+=a[i];
	}
	//zong++;
	long long l=1,r=n;
	while(l<r){
		long long uu=min(a[l],a[r]);
		if(c[l]!=c[r]){
			cnt+=uu;
			//cout<<cnt<<" "<<c[l]<<" "<<c[r]<<endl;
		}
	    //long long uu=min(a[l],a[r]);
		a[l]-=uu;
		a[r]-=uu;
		if(a[l]==0)l++;
		if(a[r]==0)r--;	
	}
	cout<<cnt;
	return 0;
} 
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b