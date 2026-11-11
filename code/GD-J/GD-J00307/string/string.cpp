#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<int,char>> a;
	for (int i = 0;i < n;i++)
	{
		pair<int,char> input;
		cin>>input.first>>input.second;
		a.push_back(input);
	}
	
	long long ans = 0;
	int j = a.size()-1;
	//cout<<j;
	for (int i = 0;i < a.size();i++)
	{
		bool asd =  true;
		while (a[i].first != 0 && asd){
		
		//cout<<i<<endl;
		if (i == j || i > j)break;
		if (a[i].first < a[j].first){
			if (a[i].second != a[j].second)ans+= a[i].first;
			a[j].first-= a[i].first;
			//a[i].first == 0;
			asd = false;
			continue;
		}
		if (a[i].first == a[j].first){
			if (a[i].second != a[j].second)ans+= a[i].first;
			j--;
			a[i].first == 0;
			asd = false;
			continue;
		}
		
		if (a[i].second != a[j].second)ans += a[j].first;
		a[i].first -=a[j].first;
		j--;
	    }
	}
	cout<<ans;
		
	
	return 0;	
} 
