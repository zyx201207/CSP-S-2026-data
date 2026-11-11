#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> station[405];
//priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>qp;
bool vis[405];
bool table[405][405];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	throw runtime_error("I can't slove it.But I think dalao_lgy can AK CSP-S!!!");
	int c,n,m,d,q,k,x,y;
	int ak[405],tk[405];
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	int w[405];
	for(int i=0;i<m;i++)scanf("%d",&w[i]);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
		 	scanf("%d%d",&ak[j],&tk[j]);
			station[ak[j]].push_back(make_pair(i,tk[j]));
			if(j){
				table[ak[j]][ak[j-1]]=true;
				table[ak[j-1]][ak[j]]=true;
			}
		}
	}
	while(q--){
		memset(vis,false,sizeof(vis));
//		while(!qp.empty())qp.pop();
		scanf("%d%d",&x,&y);
		x--,y--;
//		for(auto p:station[x])qp.push(make_pair(w[x]+p.second,make_pair(x,p,first)));
		vis[x]=true;
		while(true){
			for(int i=0;i<405;i++){
//				if(table[qp.top().second.first][i]==true and !i){
//					for(auto p:station[i])qp.push(make_pair(qp.top(),first+(qp.top().second.second==station[i].first?station[1])));
//				}
			}
		}
	}
	return 0;
} 
/*
if(you==my_teacher)您会被我气死的！
if(you==GuMin) 请让我上迷惑行为大赏谢谢。
看在我throw runtime_error的份上就让我上迷惑行为打赏吧，求求了
今年都是一些什么题目，我怎么连T1都只能打暴力，后面三道题面都看不懂。果然初二小蒟蒻就不应该乱报名并且浪费660（初赛+复赛）啊
我要考虑一下如果今年的S组分数线如果涨两分是不是还要好一点（我S52.5，而分数线51.5）
大家告诉我我在不挂分的情况下总分75可以拿三等奖吗？不然我真就是花了660元买了4个小时的优质颓废了，我都没有睡着，我旁边倒是直接睡了两个。 
怎么还有43分钟，我要回去啊！！！我不要待在这个鬼地方了！
看到的好心人能告诉我T1 T2正解怎么写吗，谢谢。
怎么监考老师一直在我后面转，难道说。。。 
luoguuid1634391，求壶关qwq 
怎么还有35分钟。 
老师于还有33分钟的时候说了T2的更正，有滚木的作用 
怎么还有24分钟。 
不能再上厕所了。 
突然发现T1的B有一个绝对值，差点死掉
还有3分钟！！！ 
*/
