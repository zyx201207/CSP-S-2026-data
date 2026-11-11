#include <iostream>
#include <vector>

using namespace std;

vector<char> GetString(vector<int> num,vector<char> word,int n)
{
	vector<char> str;
	int pos = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=pos;j<pos+num[i];j++) str.push_back(word[i]);
		pos+=num[i];
	}
	return str;
}												

int change(vector<char> str,int length)
{
	int result=0;
	int i=0,j=length-1;
	while(i<j)
	{
		if(str[i] != str[j]) result++;
		i++;j--;
	}
	
	return result;
}

int main()
{
	vector<int> num;
	vector<char> word;
	int n;
	
	cin >> n;
	int Data;
	char Words;

	for(int i=0;i<n;i++)
	{
		cin >> Data >> Words;
		num.push_back(Data);
		word.push_back(Words);
	}
	
	vector<char> str = GetString(num,word,n);  
	int length = str.size();
	int result = change(str,length);
	cout << result;
		
	return 0;
}
