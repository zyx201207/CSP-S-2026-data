#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> a;
long long maxx=-1;
long long minn=LLONG_MAX;
long long ans=0;
long long anss=0;
void check(long long l,long long r){
	if(l>r){
		return;
	}
	bool tf=false;
	long long x=(l+r)/2;
	long long ii=lower_bound(a.begin(),a.end(),x)-a.begin();
	long long cha=m;
	if(a[ii]>x){
		ii--;
	}
	if(a[ii]<x){
		cha-=x-a[ii];
		if(cha<=0){
			if(cha==0){
				ans=max(ans,1ll);
			}
			check(l,x-1);
		}
	}
	long long iii=ii+1;
	long long ds=0;
	while(a[iii]==a[ii]){
		ds++;
		iii++;
	//	cout<<"asdasdasdasda"<<endl;
	}
//	cout<<ds<<"   ds"<<endl;
	for(long long i=ii;i>=0;i--){
		cha-=x-a[i];
		if(cha<=0){
			if(cha==0){
				ans=max(ans,ii-i+1+ds);
			}
			else{
				ans=max(ans,ii-i+ds);
			}
		//	cout<<ii-i<<" "<<ii<<" sdsdsdsd";
			check(x+1,r);
			check(l,x-1);
			tf=true;
			break;
		}
	}
	if(cha<0&&tf==false){
	    ans=max(ans,ii+ds);
	    check(x+1,r);
		check(l,x-1);
		return;
	}
	if(cha>=0&&tf==false){
	//	cout<<ii+1<<" "<<ii<<" eeeeeee";
		ans=max(ans,ii+1+ds);
		check(x+1,r);
		check(l,x-1);
		return;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long cnt=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		long long x;
		cin>>x;
		cnt+=x;
		a.push_back(x);
		maxx=max(maxx,x);
		minn=min(minn,x);
	}
	sort(a.begin(),a.end()); 
	long long l=minn;
	long long r=maxx;
	cnt/=n;
	//cout<<l<<" "<<r<<endl;
	check(l,r);
//	while(l<=r){
//		long long mid=(l+r)>>1;
//		if(l==minn&&r==maxx){
//			mid=cnt;
//		}
//		long long xx=check(mid);
//		if(xx==1){
//			r=mid-1;
//		}
//		else{
//			l=mid+1;
//		}
//		cout<<mid<<" "<<ans<<" mid ans"<<endl;
//		long long anss=max(ans,anss);
//	}
	cout<<ans;
	return 0;
}
