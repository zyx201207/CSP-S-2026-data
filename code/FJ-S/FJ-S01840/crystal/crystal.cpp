#include<bits/stdc++.h>
using namespace std;
const int M=5e5+1;
bool cmd(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[M]={},b[M][2]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmd);
	int tem=0;
	for(int i=1;i<=n;i++){
		if(b[tem][0]!=a[i]){
			b[++tem][0]=a[i];
			b[tem][1]=1;
		}else{
			b[tem][1]++;
		}
	}
	int ans=1,t1=1,t2=m;
	for(int i=2;i<=tem;i++){
		t1=b[i][1],t2=m;
		for(int j=i-1;j>=1;j--){
			if(t2>=b[j][1]*(b[i][0]-b[j][0])){
				t2-=b[j][1]*(b[i][0]-b[j][0]);
				t1+=b[j][1];
			}else{
				t1+=t2/(b[i][0]-b[j][0]);
				break;
			}
		}
		ans=max(ans,t1);
	}
	cout<<ans;
	return 0;
}

