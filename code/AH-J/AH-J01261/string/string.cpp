#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef struct Node{
	int num;
	char le;
}Node;
Node l1[300010];
Node l2[300010];
int cnt1,cnt2;
int a[300010];
char c[300010];
int sum=0;
int n;
signed main(){
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum%2==0){
		int s1=sum/2;
		int i=1;
		while(s1>0&&i<=n){
			if(s1-a[i]>=0){
				l1[++cnt1].num=a[i];
				l1[cnt1].le=c[i];
				s1-=a[i];
				a[i]=0;
				i++;
			}
			else{
				l1[++cnt1].num=s1;
				l1[cnt1].le=c[i];
				a[i]-=s1;
				s1=0;
				i++;
			}
		}
		s1=sum/2;
		while(s1>0&&i<=n){
			if(s1-a[i]>=0){
				l2[++cnt2].num=a[i];
				l2[cnt2].le=c[i];
				s1-=a[i];
				a[i]=0;
			}
			else{
				l2[++cnt2].num=s1;
				l2[cnt2].le=c[i];
				a[i]-=s1;
				s1=0;
			}
		}
	}
	else{
		int s1=sum/2;
		int i=1;
		while(s1>0&&i<=n){
			if(s1-a[i]>=0){
				l1[++cnt1].num=a[i];
				l1[cnt1].le=c[i];
				s1-=a[i];
				a[i]=0;
				i++;
			}
			else{
				l1[++cnt1].num=s1;
				l1[cnt1].le=c[i];
				a[i]-=s1;
				s1=0;
			}
		}
		bool isf=1;
		s1=sum/2;
		while(s1>=0&&i<=n){
			if(isf){
				l2[++cnt2].num=a[i]-1;
				l2[cnt2].le=c[i];
				s1-=(a[i]-1);
				a[i]=0;
				i++;
				isf=0;
				continue;
			}
			if(s1-a[i]>=0){
				l2[++cnt2].num=a[i];
				l2[cnt2].le=c[i];
				s1-=a[i];
				a[i]=0;
				i++;
			}
			else{
				l2[++cnt2].num=s1;
				l2[cnt2].le=c[i];
				a[i]-=s1;
				s1=0;
			}
		}
	}
	int ans=0;
	int r=1,l=cnt2;
	while((r<=cnt1&&l>=1)){
		if(l1[r].le==l2[l].le){
			int m=min(l1[r].num,l2[l].num);
			l1[r].num-=m;
			l2[l].num-=m;
		}
		if(l1[r].le!=l2[l].le){
			int m=min(l1[r].num,l2[l].num);
			l1[r].num-=m;
			l2[l].num-=m;
			ans+=m;
		}
		if(l1[r].num==0){
			r++;
		}
		if(l2[l].num==0){
			l--;
		}
	}
	cout<<ans;
	return 0;
}
