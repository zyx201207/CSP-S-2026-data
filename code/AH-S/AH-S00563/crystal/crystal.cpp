#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[50000005],ans=0,nowsl=0,m0ans=0,s[50000005],hand=1;
void peiping(){
	for(ll i=1;i<=n;i++){
		ll j=max(hand,i);
		for(;j<=n;j++){
			if(m>=(j-i+1)*a[j]-(s[j]-s[i-1])){
				ll k=j-i+1;
				ans=max(ans,k);
			}
			else {hand=j,j=n+1 ;}
		}
	}
	return ;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==1){cout<<1;return 0;}
	if(m==0){
		ll cnt=1;
		for(ll i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				cnt++;
			}
			if(cnt>=m0ans){
				m0ans=cnt;
			}
			if(a[i]!=a[i-1]){
				cnt=1;
			}
		}
		cout<<m0ans;
		return 0;
	}
	s[0]=0,s[1]=a[1];
	for(ll i=2;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	peiping();
	/*for(int i=1;i<=n;i++){
		if(a[i]<=nowsl){
			ans++;
		}
	}*/
	cout<<ans;
	return 0;
}
/*
CSP-J/S 2026 Youji
	kewu,zhe tai ji zi shang mian jing ran mei you pin yin shu ru fa na jiu zhi neng chang hua duan shuo le
	shou xian jiu shi wo zhe chang s zu wo yu ce ke yi na 45 fen , dan shi wo gan jue wo shi ke yi na dao 60 pts de
	qi shi wo gu wo j zu zhi you 140 pts www ting shang xin de
	zhe liang chang tui yi zhi zhan wo da de hen yu kuai , jiu shi xia ci can jia zhe zhong ji bie de bi sai ke neng yao deng dao wo shang da xue le www
	na me , wo zhen de hui can jia 2031 nian de CCPC huo zhe ICPC me 
	qi shi wo ye bu zhi dao
	dang wo shang da xue de shi hou hai hui xi huan IT me
	ye bu zhi dao yi hou de wo hui bu hui hou hui xue bian cheng a
	ma shang jiu yao liu dian le , ju li bi sai jie shu zhi sheng ban xiao shi le 
	dou guai sort han shu , bu ran wo jiu ke yi na 60 pts le , ke xi le , wo bu hui xie geng kuai de pai xu
	ran hou jiu shi J zu , J zu wo ye gan jue ting ke xi de , bi jing 4 dao ti wo dou hen yan shu , di er ti mei xie chu lai zhen shi tai zao gao le
	zui hou de zui hou , wo zhu wei lai de wo tian tian kai xin !
	di yi ci yong pin yin xie you ji , gan jue ting hao xiao de
	hao le , zui hou 20 min , wo jiu zi xi jian cha yi xia ba ~
	xi wang wo S zu ke yi na dao 2= , na jiu shi jing xi zhong de jing xi le !
*/
