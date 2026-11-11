#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//并不是很想想写法，暴力吧，下午还有CSP-S
	//吊事真多
	//心脏疼
	//md
	//不会要成张xf老师了吧
	//依旧Rp++，和xyh99
	/*我说：网管（bushi（划掉）， 老师可以上厕所吗(调戏网管（bushi）中)*/
	//出去抽烟会被抓吗QwQ
	int xyh,ccf;//本来想写暴撅语言的但是怕禁赛3年
	cin>>xyh>>ccf;
	//9:36 旁边北雅的初三T1没切出来难绷
	//9:40出去上了厕所,牛魔的登记信息被铃声吓到振刀给监考逗笑了 
	//nm的谁拉了史不冲
	//md去认领一下
	//气死了
	//难崩监考一堆人看着对面的一台机子笑，盲猜是打if表的
	//神曾CSPj2025T扑克牌打52个if成功AC（醋包脚）
	//考场写日记的来
	//csp拉闸撤的来(指电苑楼总电闸(bushi
	vector<long long>a;
	//不会要用ull吧我忘记怎么写了2^30是用ll吧 
	//老了就退 
	//盲打日记假装写code给别人上压力的来
	//写了半个小时日记了，好烦不想写code 
	for(int i=0;i<xyh;i++){
		long long temp;
		cin>>temp;
		a.push_back(temp);
	}long long ans=-1;
	 for(int i=0;i<xyh;i++){
		for(int j=i+1;j<xyh;j++){
			long long tans=(a[i] and a[j]);
			if(tans>ans)ans=tans;
			//差点忘记注释掉了
			//cout<<tans<<endl;
		}
	}cout<<ans;
	return 0;
	//幽默不记得按位与了 
}/*
4 2
3 15 12 12
*/

