#include<bits/stdc++.h>
using namespace std;
long sj[500005];
long n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sj[i];
	}
	sort(sj+1,sj+1+n);//排列成有序数组 
	long long ans=0;
	long long l=1,r=2;//移动区间法 
	long long dif=sj[r]-sj[l];//初始区间值
	while(l<=r&&r<=n){
		if(dif<=m){
			ans=max(ans,r-l+1);
			r++;//区间右边界右移一位
			dif=dif+(sj[r]-sj[r-1])*(r-l);//更新区间值 
		}else{//当前区间需要的值过大 
			dif=dif-(sj[r]-sj[l]);//最右端减去最左端（返还增加能量的耗能） 
			l++;//区间左边界右移动 
		}
	}
	cout<<ans;
	return 0;
} 
