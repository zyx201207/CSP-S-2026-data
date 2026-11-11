#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long t[500005];
	for(int i=2;i<=n;i++)t[i]=a[i]-a[i-1];
	long long l=2,r=2,ti=t[2],num=1,ans=-10,cha=t[2];
	while(r<=n){
		if(l==r&&ti+t[r+1]*(num+1)>m){
			l++,r++;
			ti=t[l];cha=t[l];
			continue;
		}
		if(ti+t[r+1]*(num+1)<=m){
			ti+=t[r+1]*(num+1);
			num++;
			r++;
			cha+=t[r];
			ans=max(ans,num);
		}else{
			num--;
			ti-=cha;
			cha-=t[l];
			l++;
		}
	}cout<<ans+1;
	return 0;
}/*陈饲吗he 
		帅气*** 
    ---- 
   \* *| 
   \-  |
	---
	莆田北大附中
	特别扫码
	全家pc
	一个人拍全家福
	只有球没有条
	是0 cu m
	区区
	。。。。。
	哎 区区ccf
	才500多
	还是太便宜了。。。。。。
	没事送她了
	温馨提示：
	信竟没有自制力真的别学
	
	
	昆虫记（蛊真人 ）
	落魄谷中寒风吹
		春秋蝉鸣少年归
					---古月方源
	宿命又如何，大爱仙尊！！！！
	青茅山->白骨山->三王传承->狐仙福地->北原->八十八角真阳楼->瑯玡福地
	定仙游蛊 第二转空窍蛊 招灾蛊 智慧蛊 乐山乐水蛊 净尘蛊 解谜蛊 
	忘了。。。。。。。。。。。
	
	峡谷对抗四区
	1.劳达 全峡谷技能衔接性最好
		有一要等二 
		有二要等一 
		有一有二要等大 
		有二有大要等闪 
		有大有闪要等墙
		最后还得看队友
	2.劳布 真伤大能
		依旧绝对免疫
		依旧大招疏散人群 
*/ 
