#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[560272];
int sum[560272];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		int ans=1;
		for(int i=2;i<=n;i++){
			int cnt=0;
			for(int j=1;j<i;j++){
				cnt+=(a[i]-a[j]);
			}
			if(cnt<=m) ans=i;
		}
		cout<<ans<<endl;
	}
	else {
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		} int ans=1;
		for(int i=n;i>=1;i--){
			if((a[i]*i)-sum[i]<=m) ans=i;
		} cout<<ans<<endl;
	}
	return 0;
}
/*
under sea
moonbeam go through cloud sending sliver light
hiding the croud fading in to sea
sea wave wash the blood strains try to push you back
sea is wetting your dress try to warm you up
listen to the deep sea whose sadness is leading 
soul fade into the sea no one will wake you up
you say you love the salty sea wind
stepping on the wet beach 
you said dead one`s body should be back in the sea
you ask me where I go if I leave
who can remeber me can the world be buried in sea
in mist 
I want to stay in the mist fighting my self losing my soul
I like to stay in the mist don`t call me up just until night
when the day is just a moive I am right here practicing alone
looks like this thing is easy this condition no one save me
talking to myself i`m obessed with it
pegon hug the crow what a big funny joke
they laugh at me and say I was a fool
the world is large and unclear
colorful world in the mist looks much clearer than in the sky
their black white and gray heart
thinking selfishly I have got all of their bad meen rules
should I give up it now
you sound like uederneth the deep sea
don`t doubt it you can breath you can live
I`m at the place which makes your sound turn clearer than before
you have so much weakness (in the mist)
*/
