#include <bits/stdc++.h>
using namespace std;

const int MAXM = 3e5 + 5;
int card[MAXM];
vector < int > pos[MAXM];
int n, m;
int have[MAXM];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
//	freopen("card.err", "w", stderr);
	
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> card[i];
		pos[card[i]].push_back(i); 
	}
	
	for (int k = 1; k <= n; k++)
	{
		
//		cerr << "_____" << k << "_____\n";
		
		for (int i = k; i <= n; i++)
		{
			int j = 0;
			
//			cerr << "card[" << i << "] = " << card[i] << endl;
			
			for ( ; j < pos[card[i]].size(); j++)
			{
				if (pos[card[i]][j] == i) break;
			}
			
//			cerr << "j = " << j << endl;
//			cerr << "i = " << i << endl;
			
			if (j == pos[card[i]].size() - 1)
			{
				have[card[i]] ++;
				
//				cerr << card[i] << " " << have[card[i]] << " " << i << endl;
				
			}
			
			
			
			else 
			{
				
//				cerr << "i = " << i << endl;
//				cerr << "size = " << pos[card[i]].size() << endl;
				
				i = pos[card[i]][j + 1] - 1;
				
				/*
				if (j + 1 == pos[card[i]].size() - 1) 
				{
					have[card[i]] ++;
					
					cerr << card[i] << " " << have[card[i]] << " " << i << endl;
					
				}
				*/
			}
		}
	}
	
	for (int i = 1; i <= m; i++)
	{
		cout << have[i] << " ";
	}
	
	return 0;
}
