#include<iostream>
using namespace std;
using ll=long long;
const int N=2e5+10;
struct st{
	ll num;
	int alph;
} s[N],a[N];
int n;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		char c;
		ll num;
		cin>>num>>c;
		s[i].num=num;
		s[i].alph=c-'a';
		sum+=num;
	}
	ll cnt=0;
	ll tmp=0;
	ll cut;
	for(int i=1;i<=n;i++){
		if(tmp==sum/2&&sum%2==0)cut=cnt;
		if(sum%2==0&&tmp+1<=sum/2&&tmp+s[i].num>=sum/2+1){
			cnt++;
			a[cnt]={sum/2-tmp,s[i].alph};
			cut=cnt;
			cnt++;
			a[cnt]={tmp+s[i].num-sum/2,s[i].alph};
		}
		else if(sum%2==1&&tmp+1<=sum/2+1&&tmp+s[i].num>=sum/2+1){
			if(sum/2-tmp>0){
				cnt++;
				a[cnt]={sum/2-tmp,s[i].alph};
			}
			cut=cnt;
			if(tmp+s[i].num-sum/2-1>0){
				cnt++;
				a[cnt]={tmp+s[i].num-sum/2-1,s[i].alph};
			}

		}else {
			cnt++;
			a[cnt]={s[i].num,s[i].alph};
		}
		tmp+=s[i].num;
	}
	ll l=1,r=cnt;
	ll ans=0,ln=a[l].num,rn=a[r].num;
	while(l<r){
		if(a[l].alph!=a[r].alph){
			if(ln>rn){
				ans+=rn;
				ln-=rn;
				r--;
				rn=a[r].num;
			}else if(ln<rn){
				ans+=ln;
				rn-=ln;
				l++;
				ln=a[l].num;
			}
			else{
				ans+=ln;
				l++;
				r--;
				ln=a[l].num;
				rn=a[r].num;
			}
		}else{
			if(ln>rn){
				ln-=rn;
				r--;
				rn=a[r].num;
			}else if(ln<rn){
				rn-=ln;
				l++;
				ln=a[l].num;
			}else{
				l++;
				r--;
				ln=a[l].num;
				rn=a[r].num;
			}
		}
	}cout<<ans;
	return 0;
} 
