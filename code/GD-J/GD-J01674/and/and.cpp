#include<cstdio>
#include<iostream>
#include<vector>
#include<stack> 
#include<algorithm>
using namespace std;

vector<int> a;//最大2^30，而int最大是2^31-1，空间够用
int Answer=0;//最大答案 
stack<int> Temp;//临时存储答案

int n, m;//要被输入的数据 

void DFS(int ElementID, int Layer)//Layer：还有多少个元素可选 
{
	Temp.push(Temp.top()&a[ElementID]);
	if(Layer==0)
	{
		//获取更大的结果 
		Answer=max(Answer, Temp.top());
		Temp.pop();
		return;
	}
	for(int i=ElementID+1;i<n-Layer+1;i++)
	{
		//向深处递归 
		DFS(i, Layer-1);
	}
	Temp.pop();
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	//短路1：a[i]==pow(2, k[i])-1 
	bool All=1;
	for(int i=0;i<n;i++)
	{
		int Temp=a[i];
		bool All_1=1;//是不是每一位都是1 
		while(Temp>0)
		{
			if(Temp%2==0)All_1=0;//有一位不是1就全盘否定该短路 
			Temp/=2;
		}
		if(All_1==0)All=0;//不是的话，就没有这个短路 
	}
	if(All==1)
	{
		//短路处理 
		sort(a.begin(), a.end());//排序
		//从最后往前面进行按位与，因为每一位都是1，所以最终结果必然是被遍历过的最小的那个 
		Answer=1073741823;
		for(int i=n-1;i>n-1-m;i--)
		{
			Answer&=a[i];
		}
		cout<<Answer;
		return 0;
	}
	//短路2：log2(n)%1==0&&a[i]==i-1 
	bool OK=1;//前面的每一位都得是0，这个变量才能是1 
	int Temp2=n;
	while(Temp2>=2)
	{
		if(Temp2%2==1)OK=0;//有一个1就全盘否定该短路 
		Temp2/=2;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!=i)OK=0;//有一个a[i]!=i就全盘否定该短路 
	}
	if(OK)
	{
		Answer=1073741823;
		int Move=1;//移动空间数量 
		for(int i=0;i<m;i++)
		{
			Answer&=a[n-Move];
			Move*=2;
		}
		cout<<Answer;
		return 0;
	}
	//普通情况 
	Temp.push(1073741823);
	for(int i=0;i<n-m+1;i++)//下一层可以选择m-1个元素 
	{
		DFS(i, m-1);//第一个元素选择i 
	}
	cout<<Answer;
	return 0;
}
