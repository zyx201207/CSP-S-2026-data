#include <iostream>
#include <cstdio> 
#include <stack>
using namespace std;
int m , n;
int t[32];
int a[200010];
int maxX , ac;
bool v[200010];
int updateT(int num , int d)
{
	int i  = 0;
	while (num != 0)
	{
		i++;
		t[i] += d * (num & 1);
		num >>= 1;
	}
	return i;
}
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	ac = n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
		v[i] = 1;
		maxX = max(updateT(a[i] , 1) , maxX);
	}
	for(int i = maxX ; i >= 0 ; i--)
	{
		if (t[i] >= m)
		{
			int uac = 0;
			stack<int> st;
			for (int j = 0 ; j < n ; j++)
			{
				if(v[j])
				{
					if((a[j] >> i) == 0){
						st.push(j);
						uac++;
					}
				}
			}
			if (ac - uac >= m)
			{
				ac -= uac;
				while (!st.empty())
				{
					int x = st.top();
					v[x] = false;
					updateT(x , -1);
					st.pop();
				}
			}
		}
//		for(int i = 0 ; i < n ; i++)
//		{
//			cout << v[i] <<' ';
//		}
//		cout << endl;
	}
	int ans =0;
	int j = 1;
	for (int i = 0 ; i < n ; i++){
		if(v[i])
		{
			if(j == 1)
			{
				ans = a[i];
			}
			else
			{
				ans &= a[i];
			}
			j++;
		}
		//cout << ans;
		if(j > m){
			break;
		}
	}
	cout << ans;
} 
