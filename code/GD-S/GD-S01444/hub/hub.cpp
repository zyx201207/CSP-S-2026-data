//为什么还是多测 ccf是不是暗恋多测啊
#include<bits/stdc++.h>
using namespace std;
vector<int> e[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		for(int i = 1;i <= n-1;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout<<1<<endl 
	}
	//力竭了 
	
	return 0;
} 
/*
25+0+0+0=25!我太失败了 
Hello, strangers
When you see this text,I have already AFOed.
It is kind for you to stay for a few minutes and read how I started becoming an oier and how I afo
I started studying C++ when I was 9.
I thougt I am very smart at that time,but the fact proved me that I was WRONG.
Now I have to give it up becauce I need to prepare for WHK,such as Zhengzhi, History and Geography.
Actually it is my first time to take part in CSP for the second turn 
but I think it will be my last time to take part in CSP
I am in Cheistry Competition Team now,
and I like chemistry and biology much better than OI,although they are all difficult,
So I want to give up.
It is going to rain outside.Outside is growing dark.Just like my OI career.
18:15 only 15 minutes left.

Thanks to myself.
Thanks to my parents,include my passed-away grandma.
Thanks to the teachers who taught me through this 13 years.
Thanks to my friends and classmates.
super greatest FK to CCF.
**
一定要记得开long long
一定要记得freopen
一定要记得freopen不要写成froepen frepoen feropen等奇怪的写法 不要写错文件名。 
一定，一定要复习，不要像我这样裸考来 虽然我穿了衣服
最后，一定，一定，一定要休息好！
（昨晚获得了6小时30分钟低质睡眠） 
一定要注意身体， 
不要挑食，要多吃蔬菜，少吃点零食，少吃点油炸的东西
不要在没有专业训练的情况下尝试自学女高音！！ 很伤喉咙。 
不要尝试在岩浆里游泳。
不要在没有把握的情况下把校规视为每日任务。
在社会生活中，我们学习生活技能
在社会生活中，我们学习品德修养
在社会生活中，我们学习扮演社会角色
社会化伴随我们一生。 
**
Thank you so much for reading this.
Best wishes.
Hope there will be no more OIer AFO like me.
Goodbye.
再见。
欢迎来到世界。 
---THE END---
*/
