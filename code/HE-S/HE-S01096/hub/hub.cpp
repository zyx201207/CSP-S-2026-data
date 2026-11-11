#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int a, b;
	cin >> a >> b;
	for(int i = 1;i <= 100000000;)
	{
		i++;
		if(i % 2)
			a++;
	}
	for(int i = 1;i <= b;i++)
	{
		cout << 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
 好好计划计划好h道路构成一棵树 T。 小 W 的经费有限，他计划选择恰. 好. k 座城市，在每座选中的城市里各建造一个研
发基地。为了便于这些基地之间的协作，小 W 希望选中的城市在 T 中对应的点形成
不. 超. 过. 两. 个. 连. 通. 块. 。形式化地，定义建造方案 S ? {1, 2, . . . , n} 是合. 理. 的. ，当且仅当
|S| = k，且S在 T 中形成的连通块数量不超过 2。
对于合理的建造方案 S，定义第 i (1 ≤ i ≤ n) 座城市的通. 勤. 距. 离. 为 d(i) =
minj∈S 
dist(i, j)，其中 distlllllll地，若 i ∈ S，则 d(i) = 0。定义该建造方案的通. 勤. 半. 径. 为所有城市通勤
距离的最大值，即 maxni=1 d(i)。
你需要帮助小 W 求出，所有合理的建造方案的通勤半径的最小值。































*/
