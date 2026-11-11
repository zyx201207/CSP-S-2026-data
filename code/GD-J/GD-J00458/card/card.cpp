#include <bits/stdc++.h>
using namespace std;

int m,n;
int a[100010],b[100010];
stack<int> s;
bool pd(stack<int> s){
	if(s.empty()){
		return true;
	}
	int a=s.top();
	s.pop();
	for(int i=1;i<=s.size();i++){
		if(s.top()==a){
			return false;
		}
		s.pop();
	}
	return 1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int d=1;d<=n;d++){
		for(int i=d;i<=n;i++){
			s.push(a[i]);
			if(!pd(s)){
				int aaa=s.top();
				s.pop();
				while(aaa!=s.top()){
					s.pop();
				}
			}
		}
		for(int j=1;j<=s.size();j++){
			b[s.top()]++;
			s.pop();
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;	
} 
