#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define frp(i,a,b) for(int (i)=(int)(a);i<=(int)(b);i++)
const int N=2e5+7;
struct ac{
	char c;
	int x;
}a[N],l[N],r[N],L[N];
//pair<int,char> a[N];
int n;
int cl,cr;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int tot=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		tot+=a[i].x;
	}
	int mid=tot/2,sum=0;
	int inf=0,right_now=0;
//	cout<<tot<<" ";
	if(tot%2){
		for(int i=1;i<=n;i++){
			if(sum<=mid and sum+a[i].x>mid){
//				cout<<sum+1<<" "<<sum+a[i].x<<" "<<mid<<"\n";
				if(mid-sum>0){
					l[++cl].x=mid-sum;
					l[cl].c=a[i].c;
				}
				
				if(sum+a[i].x-mid-1>0){
					r[++cr].x=sum+a[i].x-mid-1;
					r[cr].c=a[i].c;
				}
				
				right_now=1;
				inf=1;
			}
			if(!inf){
				l[++cl].x=a[i].x;
				l[cl].c=a[i].c;
			}else if(!right_now){
				r[++cr].x=a[i].x;
				r[cr].c=a[i].c;
			}
			right_now=0;
			sum+=a[i].x;
//			cout<<sum<<" ";
		}
	}else{
		for(int i=1;i<=n;i++){
			if(sum<=mid and sum+a[i].x>mid){
				if(mid-sum>0){
					l[++cl].x=mid-sum;
					l[cl].c=a[i].c;
				}
				r[++cr].x=sum+a[i].x-mid;
				r[cr].c=a[i].c;
				right_now=1;
				inf=1;
			}
			if(!inf){
				l[++cl].x=a[i].x;
				l[cl].c=a[i].c;
			}else if(!right_now){
				r[++cr].x=a[i].x;
				r[cr].c=a[i].c;
			}
			right_now=0;
			sum+=a[i].x;
		}
	}
	for(int i=1;i<=cl;i++){
		L[i].x=l[cl-i+1].x;
		L[i].c=l[cl-i+1].c;
	}
	char ln=L[1].c,rn=r[1].c;
	int ans=0;
	if(ln!=rn){
		ans+=min(L[1].x,r[1].x);
	}
	for(int i=2,j=2,si=L[1].x,sj=r[1].x;;){
//		cout<<si<<" "<<sj<<"\n";
		if(i>cl and j>cr)
			break;
		if(si>sj and j<=cr){
//			j++;
			sj+=r[j].x;
			if(r[j].c!=ln){
				if(sj>si){
					ans+=(si-(sj-r[j].x));
				}else{
					ans+=r[j].x;
				}
			}
			rn=r[j].c;
			j++;
		}else if(si<=sj and i<=cl){
			si+=L[i].x;
			if(L[i].c!=rn){
				if(si>sj){
					ans+=(sj-(si-L[i].x));
				}else{
					ans+=L[i].x;
				}
			}
			ln=L[i].c;
			i++;
		}
//		cout<<i<<" "<<j<<"\n";
	}
	cout<<ans;
	return 0;
}
