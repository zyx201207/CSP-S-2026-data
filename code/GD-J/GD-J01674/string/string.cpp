#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct Chars
{
	int Count;
	char Char;
};
struct Divide_info
{
	//分割点的信息 
	long long Location;//分割点位置 
	bool Original;//是否为原有的分割点 
};
bool cmp(Divide_info a, Divide_info b)
{
	if(a.Location!=b.Location)return a.Location<b.Location;//位置不同，看谁位置更靠前 
	else return a.Original>b.Original;//位置相同，靠前的那一项是原来的分割点 
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin>>n;
	Chars *Count=new Chars[n]{};//分配内存 
	for(int i=0;i<n;i++)cin>>Count[i].Count>>Count[i].Char;//输入
	
	long long Size=0;//字符串长度 
	for(int i=0;i<n;i++)
	{
		Size+=Count[i].Count;
	}
	
	/*
	解题思路：
	将原来的字符串倒序分割，分割后每一段内的每个字符都相同，这样可以确保将所有子串倒过来后长度每段长度和原来一样，方便进行回文操作
	分割完后，先排序并去重，再看一看每一段都是什么字符 
	知道每段都是什么字符了以后，就可以开始计算需要更改的字符的数量了 
	*/
	Divide_info *Splits=new Divide_info[2*n-2]{};//分割点数量最多为2n-2
	int Point=0;//指针 
	for(int i=0;i<n-1;i++)//正着分割 
	{
		Splits[Point].Location=Count[i].Count;//分割点移动步数 
		if(Point>0)Splits[Point].Location+=Splits[Point-1].Location;//加上上一个分割点的位置，得到当前分割点位置 
		
		Splits[Point].Original=1;//是原来的分割点 
		Point++;
	}
	for(int i=0;i<n-1;i++)//倒着分割
	{
		Splits[Point].Location=Size-Splits[i].Location;//沿着中间翻转 
				
		Splits[Point].Original=0;//不是原来的分割点
		Point++;
	}
	
	sort(Splits, Splits+Point, cmp);//给分割点排序
	//排完序后，需要去重 
	Divide_info *Unique=new Divide_info[2*n-2]{};//去重数组 
	int Upoint=0;//去重指针 
	for(int i=0;i<Point;i++)
	{
		if(i==0||Splits[i].Location!=Splits[i-1].Location)//是第一个元素，或者该元素与上一个不同的时候可以添加 
		{
			Unique[Upoint++]=Splits[i];
		}
	}
	
	char *Paragraph_char=new char[Upoint+1];//每一段的字符 
	int *Paragraph_size=new int[Upoint+1];//每一段的长度 由于原始分割点之间的距离小于10亿，后续又添加了一些分割点，因此每段的长度不可能超过10亿，只开int 
	int ID=0;//分割点ID，该变量可用于获取当前分割点的段落序数 
	Paragraph_char[0]=Count[0].Char;
	Paragraph_size[0]=Unique[0].Location;
	for(int i=1;i<=Upoint;i++)
	{
		//遍历每个分割点，如果是原来的分割点，ID就加1 
		if(Unique[i-1].Original)ID++;
		Paragraph_char[i]=Count[ID].Char;
		if(i<Upoint)Paragraph_size[i]=Unique[i].Location-Unique[i-1].Location;
		else Paragraph_size[i]=Size-Unique[i-1].Location;
	}
	
	long long Change=0;//要修改的字符数量 
	for(int i=0;i<(Upoint+1)/2;i++)
	{
		if(Paragraph_char[i]!=Paragraph_char[Upoint-i])Change+=Paragraph_size[i];
	}
	cout<<Change;
	
	//用完记得释放
	delete(Count);
	delete(Splits);
	delete(Unique);
	delete(Paragraph_char);
	delete(Paragraph_size);
	return 0;
}
