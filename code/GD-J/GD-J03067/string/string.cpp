#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int N=2e5+5;
ll n,len,a[N],m1=0,m2=0,x[N],y[N],ans=0;
char c[N],cx[N],cy[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(sum+a[i]<=len/2){
			m1++;
			x[m1]=a[i];
			cx[m1]=c[i];
		}
		else{
			if(sum<=len/2){
				m1++;
				x[m1]=len/2-sum;
				cx[m1]=c[i];
			}
			break;
		}
		sum+=a[i];
	}
	sum=0;
	for(int i=n;i>=1;i--){
		if(sum+a[i]<=len/2){
			m2++;
			y[m2]=a[i];
			cy[m2]=c[i];
		}
		else{
			if(sum<=len/2){
				m2++;
				y[m2]=len/2-sum;
				cy[m2]=c[i];
			}
			break;
		}
		sum+=a[i];
	}
	ll i=1,j=1,li=1,ri=x[1],lj=1,rj=y[1];
	while(i<=m1||j<=m2){
		if(ri==rj){
			if(cx[i]!=cy[j]) ans+=ri-li+1;
			li=ri+1,ri+=x[++i];
			lj=rj+1,rj+=y[++j];
		}
		else if(ri<rj){
			if(cx[i]!=cy[j]) ans+=ri-li+1;
			y[j]-=ri-li+1,lj=ri+1;
			li=ri+1,ri+=x[++i];
		}
		else{//ri>rj
			if(cx[i]!=cy[j]) ans+=rj-lj+1;
			x[i]-=rj-lj+1,li=rj+1;
			lj=rj+1,rj+=y[++j];
		}
//		printf("i=%lld,j=%lld,qui=[%lld,%lld],quj=[%lld,%lld]\n",i,j,li,ri,lj,rj); 
	}
	cout<<ans;
	return 0;
}
