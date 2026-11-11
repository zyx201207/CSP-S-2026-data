#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1919810],ans=1,cha[1919810],num=0;
bool aii=1,decha=1;
long long mxm(long long now){
	for(long long i=now+1;i<n;i++){
		cha[i]=(a[i]-a[i-1])*(i-now);
		//cout<<cha[i]<<" "<<a[i]<<" "<<a[i-1]<<" "<<i-now<<endl;
	}
	long long k=m,cut=1;
	for(long long i=now+1;i<n;i++){
		if(cha[i]<=k){
			k-=cha[i];
			cut++;
		}else break;
	}
	return cut;
}
void solve_baoli(){
	sort(a,a+n);
    for(long long i=0;i<n-1;i++)ans=max(ans,mxm(i));
	cout<<ans;
}
void solve_aii_decha(){
	cout<<mxm(0);
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);//注释删除！！！！！！！！！！！！
    freopen("crystal.out","w",stdout);//注释删除！！！！！！！！！！！！！！
    //wrong answer 75?
    cin>>n>>m;
    for(long long i=0;i<n;i++){
		cin>>a[i];
		if(aii&&a[i]!=i+1)aii=0;
		if(i==1)num=a[i]-a[i-1];
		else if(decha&&i>1&&a[i]-a[i-1]!=num)decha=0;
	}
    if(aii||decha){
		solve_aii_decha();
	}else{
		solve_baoli();
	}
    return 0;
}
//喂～俺个炊饼～马飞～暴力终于写对了！
