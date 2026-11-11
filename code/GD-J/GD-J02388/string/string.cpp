#include<bits/stdc++.h>
using namespace std;
long long a,b;
char c;
queue<char>e;
stack<char>f;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i = 1;i<=a;i++){
		cin>>b>>c;
		for(long long  j =1;j<=b;j++){
			e.push(c);
			f.push(c);
		}
		
	}

	long long  q;
		if(e.size()%2==1)q = e.size()/2+1;
		else q = e.size()/2;
		long long  m = q;


		for(int j =1;j<=q;j++){
			if(e.front()==f.top()){
				m--;
				e.pop();
				f.pop();
			}
		}
		cout<<m;
	

	return 0;
}
