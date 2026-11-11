#include<bits/stdc++.h>
#define long long int 
using namespace std;
//手动测试 
int cs0=0;
int cs(int n,int s){
	if(cs0==1){
		cout<<s<<":"<<n;
	}
	return 0;
}
//变量 
int a1,a2;
int num_sj[500005];
int max0;
signed main(){
	if(cs0==0){
		ios::sync_with_stdio(0);
		cin.tie(0);
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
	}
	//程序 
	cin>>a1>>a2;
	for(int i=1;i<=a1;i++){
		cin>>num_sj[i];
	}
	sort(num_sj+1,num_sj+a1);
	int num;
	for(int i=a1;i>=num;i--){
		int a3=a2;
		num=0;
		for(int j=1;j<=i;j++){
			if(num_sj[i]-num_sj[j]<=a3){
				a3-=num_sj[i]-num_sj[j];
				num++;
			}else{
				break;
			}
		}
		max0=max(num,max0);
	}
	cout<<max0;
	return 0;
} 
