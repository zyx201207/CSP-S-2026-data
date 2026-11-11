#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],n,d,b[10000],cnt=1e9,ans,sum;
bool check(int q,int z){
	int ss;
	if((q-z)>=0){
		ss=q-z;
	}else{
		ss=(q-z)/-1;
	}
	if(ss>d){
		return false;
	}else{
		return true;
	}
}
void kk(int qi,int zh,int step){
	if(qi==zh){
		return ;
	}
	for(int i=0;i<step;i++){
		sum=0;
		if(check(step-i,zh)){
			kk(qi+step-i,zh,step-i);
			sum++;
		}
		cnt=min(cnt,sum);
	}
}
int main(){
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		int b[10000]={};
		for(int j=d+1;j<=n;j++){
			kk(1,j,d);
			b[sum]++;
			if(b[cnt]==2){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
