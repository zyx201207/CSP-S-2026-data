/*这道题用图论，根据我的理解，需要将站台与展厅距离合并合并权值为两数相加，将线路缩为一个点（只计算步行距离），然后使用最短路计算这属于暴力的算法大概能过3个得分点我觉得应该差不多啊吧                                                                                                        */
#include<bits/stdc++.h>
using namespace std;
struct co{
	long long used,num;
};
co lovecyt[999999];


int djistela(){
	return 1;
}

long long n,m,a[999999];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n+m;i++){
		lovecyt[i].num=1;
		 
	}
	for(int i=2;i<=n;i++){
		lovecyt[i].num=lovecyt[i-1].num;
		if(m-lovecyt[i-1].used>=(lovecyt[i].num-lovecyt[i-1].num)){
				lovecyt[i].num=lovecyt[i-1].num+1;
				lovecyt[i].used =lovecyt[i-1].used +lovecyt[i].num-lovecyt[i-1].num;   
				cout<<lovecyt[i].used;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<lovecyt[i].used<<' ';
		
		cout<<lovecyt[i].num<<' ';
		cout<<endl;
	}        
	return 0; }
