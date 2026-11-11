#include<iostream>
#include<vector>
using namespace std;

bool isRepeat(vector<int> vec,int num)
{
	for(int i=0;i<vec.size();i++)
		if(num == vec[i]) return 1;
	return 0;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> card;
	
	int temp;
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		card.push_back(temp);
	}
	vector<int> result;
	for(int k=0;k<m;k++) result.push_back(0);
	
	vector<int> game;
	for(int i=0;i<n;i++)   //n¾ÖÓÎÏ· 
	{
		for(int j=i;i<n;j++)
		{
			if(isRepeat(game,card[j])==1)
			{
				while(game.back() != card[j]) game.pop_back();
				temp = card[j];
				game.push_back(temp);
			} 
			for(int k=0;k<m;k++)
				if(isRepeat(result,k+1) == 1) result[k]+=1;
		}
	}
	
	for(int i=0;i<m;i++) cout << result[i] << ' ';
	
	
	return 0;
}
