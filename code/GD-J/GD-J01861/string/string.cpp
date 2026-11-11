#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct WORD{
	ll count;
	char word; 
}a[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	//cout<<n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].count>>a[i].word;
		sum+=a[i].count;
	}
	ll ce=ceil(1.0*sum/2);
	ll now1=1,ln=0,rn=0;
	ll cl=1,cr=n;
	ll ans=0;
	while(now1<=ce&&cl<cr){
		//cout<<now1<<"\n";
//		if(a[cl].count+ln>=ce){
//			
//		}
		if(a[cl].word==a[cr].word){
			//cout<<now1<<' '<<a[cl].word<<'-';
			ll lix=a[cl].count+ln-now1+1;
			ll liy=a[cr].count+rn-now1+1;
			ll kx=min(lix,liy);
//			cout<<liy<<' '<<lix<<'=';
			if(lix>liy){
				now1=now1+kx;
				rn+=a[cr].count;
				cr--;
			}else if(lix<liy){
				now1=now1+kx;
				ln+=a[cl].count;
				cl++;
			}else{
				//cout<<kx<<" "<<now1;
				now1=now1+kx;
				//cout<<' '<<now1<<'=';
				ln+=a[cl].count;
				rn+=a[cr].count;
				cl++;
				cr--;
			}
		}else{
			//cout<<now1<<"= ";
			ll lix=a[cl].count+ln-now1+1;
			ll liy=a[cr].count+rn-now1+1;
			ll kx=min(lix,liy);
			ans+=kx;
			if(lix>liy){
				//cout<<now1+min(lix,liy)<<'\n';
				now1=now1+kx;
				rn+=a[cr].count;
				cr--;
			}else if(lix<liy){
				now1=now1+kx;
				ln+=a[cl].count;
				cl++;
			}else{
				now1=now1+kx;
				ln+=a[cl].count;
				rn+=a[cr].count;
				cl++;
				cr--;
			}
		}
	}
	cout<<ans;
}
/*
5
2 a
1 b
1 c
1 a
1 b
*/
