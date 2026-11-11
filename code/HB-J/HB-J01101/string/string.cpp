#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+7;
int n;
int a,t,len;
int ans[N],minn = 1e9+11;
char c[N];
string s;

bool check(string s)
{
	t = len;
	for(int i = 0;i < len;i++)
	{
		t--;
		//cout << s[i] <<" "<<s[t]<<(s[i] != s[t])<<endl;
		if(s[i] != s[t]){
			return 0;
		}
	}
	
	return 1;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a >> c[i];
		
		for(int j = t;j<a + t;j++)
		{
			s += c[i];
		}
		t += a;
	}
	
	len = s.size();
	//cout <<len <<" "<< s <<" ";
	t = 0;
	string s1 = s;
	if(check(s) == 1)
	{
		cout << 0;
		return 0;
	}
	for(int i = 0;i < len;i++)
	{
		for(int j = 0;j < n;j++)
		{
			
			s1[i] = c[j];
			ans[t]++;
			if(check(s1)){
				t++;
				s1 = s;
			}
		}
	}
	for(int i = 0;i < n;i++)
	{
		if(ans[i]<minn and ans[i] != 0)
			minn = ans[i];
	}
	
	cout << minn;
	return 0;
}
