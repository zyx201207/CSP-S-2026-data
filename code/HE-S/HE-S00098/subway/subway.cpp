#include<bits/stdc++.h>
using namespace std;
int w[560272];
struct railway{
	int station,stime;
}a[560272];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,d,q; cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j].station>>a[i][j].stime;
		}
	}
	while(q--){
		int x,y; cin>>x>>y;
	}
	return 0;
}
/*
调查中（searching）
放弃规则后 是否还值得(give up all the rules will I be worth it)
放弃救赎后 世界是灰色(give up all blessing the world is in gray)
放弃怯懦后 又如何抉择(give up my corage how should I choose it)
恶意在交叠 忘记仍哽咽(is folding forget then drop tears)
不解绝处中 怎能去面对(don`t know at the end how should I face it)
不懂轮回中 何人会慈悲(don`t know in who will be )
不甘犹豫中 冷漠是原罪(don`t care in quite is the fault)
请求不再错 最后仍磊落(please don`t be wrong now the world is bright last)
倘若时间之诺分得出错对(if time will decide up who is wrong or true)
怎疑撕心烈火鼎沸的苦泪(why there so much sadness so much tears drop down)
镜面倒映出的你我悄声破碎(the mirror reflect you then I broken in pieces) 
期待永恒的回馈也许已走向明媚(waiting for unchange answer it might has gone to the bright)
放弃规则后 是否还值得(give up all the rules will I be worth it)
放弃救赎后 被评为罪恶(give up all blessing then I am a villian) 
放弃怯懦后 又如何抉择(give up my corage how should I choose it)
恶意在交叠 烈焰仍哽咽(is folding fire dropping tears)
不解绝处中 怎能去摧毁(don`t know at the end how should I Destroy) 
不懂清白中 何人是魔鬼(don`t know in who is a demon)
不甘犹豫中 冷漠是防备(don`t care in quite is defend)
请求不再错 最后仍磊落(please don`t be wrong now the world is bright last)
看……别时容易见时难 愧疚爱意皆参半
但……眷恋曾望眼欲穿 燃烧最后的严寒
*/ 
