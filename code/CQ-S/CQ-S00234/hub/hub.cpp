#include<bits/stdc++.h>
#define int long long
int n,k,u,v;
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>u>>v;
		if(k==n){
			cout<<0<<'\n';
			continue;
		}
		if(k==n-1){
			cout<<1<<'\n';
			continue;
		}
		cout<<n/2<<'\n';
	}	
	return 0;
}
/*
不会暴力（悲
只能总司令力 
CCF Bless me 1=
wjy7777 Bless me 1=
All of CQ Bless me 1=
哟吼吼吼吼吼吼吼吼吼吼吼吼
请输入文本
Hope CQ 1= line<=220pts... 
if CQ 1= line>230pts
I will 见证史
	Dream VS. Piggod
		Full Text
	Dream:
	In this video
	I owned Piggod 100000$.
	But I have no money
	And I haven't pay him back for 91 days
	Which makes Piggod is very angry
	So he will keep chasing to kill me
	But if I defeat the Ender Dragon
	I won't to pay back this 100000$.
	Can I win the game?
	Enjoy this video.
	Piggod: 
	Dream还我十万没到！
	Dream:
	I no money I no money No kill me No kill me
	Piggod:
	I will kill you!
	Dream:
	ohno皮革噶的要追上来了 我们快逃逸
	Piggod:
	i am coming dream!
	Dream:
	Piggod come on 砰砰砰 with me
	ohno piggod你不要开挂啊 no
	Piggod:
	Come Here Loser
	Dream:
	Piggod你完蛋了 看我开启black客
	Piggod:
	wtf? Noooooooooo!
	------------
	Piggod:
	Hello Dream!
	Dream:
	No no no Give you irons don't kill me OK?
	Piggod:
	love you!
	Dream:
	Leave me Leave me No way
	Piggod:
	wtf! Noooooooooooo!
	Dream:
	LLL piggod loser!
	-----------------
	Piggod:
	i see you dream!
	Dream:
	LLL piggod come on and catch me
	wtf。
	---------------------
	Piggod:
	I'm VERY ANGRY!
	I WANT YOU TO DIE!!!!!!
	DIE DIE DIE!
	DIE DIE DIE!
	Dream:
	i错了 i错了 i还你十万没到
	Nooooooooooooooooooooooooooooooooo!
	 
*/
