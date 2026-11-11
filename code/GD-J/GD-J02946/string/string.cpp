#include<bits/stdc++.h>
using namespace std;
deque<long long> a;//存数量 
deque<char> c;//存字符 
long long n,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	cout<<"------------------"<<'\n'; 
	cin>>n;
	long long in1;
	char in2;
//	cout<<"------------------"<<'\n'; 
	for(int i=0;i<n;i++){
		cin>>in1>>in2;
		a.push_front(in1);
		c.push_front(in2);
	}
	int xa,ya;
	char xc,yc;
	while(a.size()>1){
//		cout<<"------------------"<<'\n'; 
		if(a.size()==1) break;
		xa=a.front();
		ya=a.back();
		xc=c.front();
		yc=c.back();
		a.pop_front();
		a.pop_back();
		c.pop_front();
		c.pop_back();//提取数量与字符 
		if(xa>ya){
			a.push_front(xa-ya);
			c.push_front(xc);
		}else if(ya>xa){
			a.push_back(ya-xa);
			c.push_back(yc);//区间数量不等塞回去多的地方
		}
		if(xc!=yc) ans+=min(xa,ya);
	}
	cout<<ans;
	return 0;
} 
