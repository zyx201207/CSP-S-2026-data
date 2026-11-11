#include<bits/stdc++.h>
using namespace std;
int n;
long long ans = 0;
struct stri{
	long long chan;
	char zi;
}c[200005];
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> c[i].chan >> c[i].zi;
	for(int i = 1 , j = n;i <= j;)
	{
		if(c[i].zi == c[j].zi)
		{
			if(c[i].chan >= c[j].chan) c[i].chan -= c[j].chan , c[j].chan = 0;
			else c[i].chan = 0 , c[j].chan -= c[i].chan;
			i++ , j--; 
		}
		if(c[i].chan >= c[j].chan && c[i].zi != c[j].zi)
		{
			ans += c[j].chan;
			c[i].chan -= c[j].chan , c[j].chan = 0;
			c[j].zi = c[i].zi;
			if(c[i].chan == 0) i++;
			j--;
		}
		if(c[i].chan < c[j].chan && c[i].zi != c[j].zi)
		{
			ans += c[i].chan;
			c[j].chan -= c[i].chan , c[i].chan = 0;
			c[i].zi = c[j].zi;
			if(c[j].chan == 0) j--;
			i++;
		}
	}
	cout << ans;
	return 0;
}
