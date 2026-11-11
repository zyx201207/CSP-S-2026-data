#include <iostream>
#include <vector>

using namespace std;
string turnTen_toTwo(int num_10)
{
	string temp;
	int i=0;
	
	while(num_10>=2)
	{
		temp[i] = num_10%2;
		i++;
		num_10/=2;
	}
	temp[i+1] = num_10;
	
	string num_2;
	for(int i=0;i<temp.length();i++)
		num_2[i] = temp[temp.length()-i-1];
		
	return num_2;
}
int main()
{
	vector<int> vec;
	int n,m;
	cin >> n >> m;
	int num;
	for(int i=0;i<n;i++)
	{
		cin >> num;
		vec.push_back(num);
	}
	
	vector<string> Data;
	for(int i=0;i<vec.size();i++)
		Data.push_back(turnTen_toTwo(vec[i]));
		
	for(int i=0;i<Data.size();i++) cout << Data[i] << ' ';
	return 0;
}




