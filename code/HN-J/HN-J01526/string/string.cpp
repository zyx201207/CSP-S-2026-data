#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int arr[200005],l[200005],r[200005];
string s;
void compute(int x,int num,bool flag){
	int rnum=num,rx=x;
	if(!flag){
		rnum=num+1;
		rx=x;
	}else{
		rnum++;
		num--;
	}
	if(r[rx]<rnum){
		rx++;
	}
	if(l[x]>num){
		x--;
	}
	for(int i=x,j=rx;num>=1 && rnum<=r[n];){
		int tmpr=r[j]-rnum+1,tmpl=num-l[i]+1;
		if(s[i]==s[j]){
			if(tmpr>tmpl){
				num=l[i]-1;
				rnum+=tmpl;
			}else{
				rnum=r[j]+1;
				num-=tmpr;
			}
		}else{
			if(tmpr>tmpl){
				ans+=tmpl;
				num=l[i]-1;
				rnum+=tmpl;
			}else{
				ans+=tmpr;
				rnum=r[j]+1;
				num-=tmpr;
			}
		}
		if(num<1 || rnum>r[n]){
			break;
		}
		while(num<l[i] && i>=1){
			i--;
		}
		while(rnum>r[j] && j<=n){
			j++;
		}
	}
	cout<<ans;
	return;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0,cnt=0;
	s+=' ';
	for(int i=1;i<=n;i++){
		char c;
		int x;
		cin>>x>>c;
		if(c==s[cnt]){
			arr[cnt]+=x;
		}else{
			s+=c;
			arr[++cnt]=x;
		}
		sum+=x;
	}
	n=cnt;
	for(int i=1;i<=n;i++){
		l[i]=r[i-1]+1;
		r[i]=r[i-1]+arr[i];
	}
	//第二步:找到中间点x
	int mid=(sum%2==0?sum/2:sum/2+1);
	bool flag=sum%2;
	for(int i=1;i<=n;i++){
		if(r[i]>mid){
			compute(i,mid,flag);
			break;
		}
	} 
	return 0;
}
/*
15min瞬秒T1
我常常追忆过去，生命的瞬间定格在脑海，我将身后的时间揉卷折叠化为天上朵朵白云…… 
*/
