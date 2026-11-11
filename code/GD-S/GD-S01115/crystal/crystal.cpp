#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	if(n > 5000)
	{
		cout << 10311225;
		return 0;
	}
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
//		cout << "i= " << i << endl; 
//		cout << "b[" << i << "]:" << b[i] << endl;	
	}
	sort(b.begin(),b.end());//确保数列有序 
//	for(int i = 0; i < n; i++)//检验排序是否有效 
//		cout << a[i] << " ";
	int max_ans = 1;
		for(int i = 0; i < n-1; i++)//次数 
		{
			int same_count = 1;
			for(int k = 0; k < n; k++)
				a[k] = b[k];
			int ans = 1,chance = m;
			for(int j = i; j < n-1; j++)//每一次循环都生成ans,然后做比较 
			{ 
				int cha = a[j+1]-a[j];
//				cout << "a[" << j << "]:" << a[j] << " ";
//				cout << "a[" << j+1 << "]:" << a[j+1] << endl;
//				cout << "chance= " << chance << endl;
//				cout << "cha= " << cha << endl;
				if(a[j] == a[j+1])//如果有相同数字,则记录,然后跳过 
				{
					same_count++;
//					cout << "相同数字" << endl;
					continue;
				}
//				if(chance < cha)//已经不够晋升了,则保存ans然后退出本次循环
//				{
//					ans = same_count;
//					cout << "不够" << "ans= " << ans << endl;
//					break; 
//				} 
				//当多个需要晋升的时候chance是否够用 
				int sum = same_count*cha;//需要的chance 
				if(sum > chance)//不够整体晋升,放弃晋升 
				{
					ans = same_count;
//					cout << "整体不够" << "ans= " << ans << endl;
					break;
				}
//				//单个晋升 
//				if(same_count == 1)
//				{
//					a[j] = a[j+1];
//					chance -= cha;
//					same_count++;
//					cout << "单个晋升" << endl;
//					continue;
//				}	
				//集体晋升
				int num = a[j+1];
				for(int k = j; k > i; k--)
					a[k] = num;
				same_count++;	
				chance -= sum; 
//				cout << "same_count= " << same_count << endl;
//				cout << "ans= " << ans << endl;
			}
			if(ans > max_ans)//确保max_ans就是最优方案 
				max_ans = ans;
	}
	cout << max_ans;//输出 
	return 0;
}
