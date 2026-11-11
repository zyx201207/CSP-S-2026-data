#include<bits/stdc++.h>
using namespace std;
int func(string s)
{
	int n=s.size();
	stack<int> st;
	for(int i=0;i<n;i++){
		char c;
		c=s.back();
		st.push(c-'0');
		s.pop_back();
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum=sum*10+st.top();
		st.pop();
	}
	return sum; 
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	int c1,s1,c2,s2;
	char s1z,s2z;
	for(int i=1;i<=4;i++){
		if(i==1){
			cin>>c1;
			continue;
		}
		else if(i==2){
			cin>>s;
			s1z=s.back();
			s.pop_back();
			s1=func(s);
		}
		else if(i==3){
			cin>>c2;
			continue;
		}
		else if(i==4){
			cin>>s;
			s2z=s.back();
			s.pop_back();
			s2=func(s);
		}
	}
	if(c1==c2){
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			if((s1z<='C'&&s2z<='C')||(s1z>='D'&&s2z>='D')){
				cout<<"1";
				if((s1z-s2z==1)||(s2z-s1z==1)||(s1z=='D'&&s2z=='F')||(s1z=='F'&&s2z=='D')) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
