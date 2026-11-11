#include <bits/stdc++.h>
using namespace std; 

long long n, num; 

struct node
{
	long long a; 
	char c; 
}; 

int main()
{
	ios::sync_with_stdio(0); 
    cin.tie(0);
	
	freopen("string.in", "r", stdin); 
	freopen("string.out", "W", stdout); 
	
	cin >> n; 
	vector <node> s(n+10); 
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i].a >> s[i].c; 
		num += s[i].a; 
	}
	
	vector <node> st1(n+1); 
	vector <node> st2(n+1); 
	
	long long sum = 0;
	int i = 1, j = n, head1 = 1, title1 = 0, head2 = 1, title2 = 0; 
	
	while(i <= n || j >= 1)
	{
		if (head1 > title1 && i <= n)
		{
			title1++; 
			st1[title1] = s[i]; 
			i++; 
		}
		if (head2 > title2 && j >= 1)
		{
			title2++; 
			st2[title2] = s[j]; 
			j--;  
		}
		if (st1[head1].c == st2[head2].c) sum += min(st1[head1].a, st2[head2].a); 
		if (st1[head1].a < st2[head2].a) st2[head2].a -= st1[head1].a, head1++; 
		else if (st1[head1].a > st2[head2].a) st1[head1].a -= st2[head2].a, head2++; 
		else head1++, head2++; 
	}
	cout << (num-sum)/2; 
	
}
