#include<bits/stdc++.h>
using namespace std;
const int Maxn=2e5+10;
struct Node{
	char x;
	int num=0,beg=-1,end=-1;
}a[Maxn];
int n,cur=0,cur1=0,cur2=0,sum=0;char last=' ';
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char tmp1;int tmp2;
		cin>>tmp2>>tmp1;
		sum+=tmp2;
		if(tmp1==last) {a[cur].num+=tmp2;}
		else {cur++;a[cur-1].end=sum-tmp2;a[cur].x=tmp1;a[cur].num=tmp2;a[cur].beg=sum-tmp2+1;}
		last=tmp1;
	}
	a[cur].end=sum;
	int mid=sum/2+1,ans=sum-mid+1,mid_cur=cur/2+1;
	//cout<<mid<<' '<<ans;
	for(int i=1;i<=mid_cur;i++){
		//cout<<a[i].x<<' '<<a[i].beg<<' '<<a[i].end<<' '<<a[i].num;
		for(int j=cur;j>=mid_cur;j--){
			if(a[j].end<=(sum+1-a[i].beg)&&a[j].beg>=(sum+1-a[i].end)&&a[i].x==a[j].x) {
				if(a[j].beg<=mid)ans-=((a[j].end-a[j].beg)+1)/2;
				else ans-=abs((a[j].end-a[j].beg)+1);
				break;
			}else if(a[j].end>=(sum+1-a[i].beg)&&a[j].beg<=(sum+1-a[i].end)&&a[i].x==a[j].x) {
				if(a[j].beg<=mid)ans-=((a[j].end-a[j].beg)+1)/2;
				else ans-=abs((sum+1-a[i].beg)-(sum+1-a[i].end)+1);
				break;
			}else if(a[j].end<=(sum+1-a[i].beg)&&a[j].beg<=(sum+1-a[i].end)&&a[i].x==a[j].x) {
				if(a[j].beg<=mid)ans-=((a[j].end-a[j].beg)+1)/2;
				else ans-=abs((a[j].end)-(sum+1-a[i].end)+1);
				break;
			}else if(a[j].end>=(sum+1-a[i].beg)&&a[j].beg>=(sum+1-a[i].end)&&a[i].x==a[j].x) {
				if(a[j].beg<=mid)ans-=((a[j].end-a[j].beg)+1)/2;
				else ans-=abs((sum+1-a[i].beg)-(a[j].beg)+1);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
