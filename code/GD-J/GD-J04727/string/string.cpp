#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,houcnt,qiancnt;
struct node{
	int a;
	char c;
}a[200001],pre[200001],hou[200001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt++;
		cin>>a[cnt].a>>a[cnt].c;
		sum+=a[cnt].a;
		if(a[cnt].c==a[cnt-1].c&&cnt>0)a[cnt-1].a+=a[cnt].a,cnt--;
	}
	int newsum=0;
	for(int i=1;i<=cnt;i++){
		newsum+=a[i].a;
		if(newsum>=(sum+1)/2&&newsum-a[i].a<(sum+1)/2){
			houcnt++,qiancnt++;
			hou[houcnt].a=newsum-sum/2-(sum&1);
			pre[qiancnt].a=a[i].a-hou[houcnt].a-(sum&1);
			hou[houcnt].c=a[i].c,pre[qiancnt].c=a[i].c;
			if(hou[houcnt].a<=0)houcnt--;
			if(pre[qiancnt].a<=0)qiancnt--;
		}
		else if(newsum>=(sum+1)/2){
			houcnt++;
			hou[houcnt]=a[i];
		}
		else{
			qiancnt++;
			pre[qiancnt]=a[i];
		}
	}
	reverse(hou+1,hou+1+houcnt);
//	for(int i=1;i<=qiancnt;i++)cout<<pre[i].a<<","<<pre[i].c<<endl;
//	cout<<endl;
//	for(int i=1;i<=houcnt;i++)cout<<hou[i].a<<","<<hou[i].c<<endl;
	int l=1,r=1,ans=0;
	while(l<=qiancnt&&r<=houcnt){
		if(pre[l].c!=hou[r].c){
			ans+=min(pre[l].a,hou[r].a);
			int t=min(pre[l].a,hou[r].a);
			pre[l].a-=t,hou[r].a-=t;
			if(!pre[l].a)l++;
			if(!hou[r].a)r++;
		}
		else{
			int t=min(pre[l].a,hou[r].a);
			pre[l].a-=t,hou[r].a-=t;
			if(!pre[l].a)l++;
			if(!hou[r].a)r++;
		}
	}
	cout<<ans;
}
