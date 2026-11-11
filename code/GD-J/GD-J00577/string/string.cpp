#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	cin>>a;
	vector<long long> b(a);
	stack<long long> b2,b3,b4;
	vector<char> c(a);
	stack<char> c2,c3,c4;
	long long haf=0,haf2=0,s2=0,s3=0;
	for(int i=0; i<a; i++) {
		cin>>b[i];
		cin>>c[i];
		haf+=b[i];
	}
	bool ls=true;
//	cout<<"L:";
	for(int i=0; i<a; i++) {
		if(haf2+b[i]<=(haf)/2) {
			b2.push(b[i]);
			c2.push(c[i]);
//			cout<<b2.top()<<c2.top()<<" ";
			s2++;
		} else if(ls==false) {
			b3.push(b[i]);
			c3.push(c[i]);
//			cout<<b3.top()<<c3.top()<<" ";
			s3++;
		} else {
			if(haf/2!=haf2) {
				b2.push((haf)/2-haf2);
				c2.push(c[i]);
//				cout<<b2.top()<<c2.top()<<" "<<endl;
//				cout<<"R:";
				s2++;
				b3.push(b[i]-((haf)/2-haf2));
				c3.push(c[i]);
//				cout<<b3.top()<<c3.top()<<" ";
				s3++;
			} else {
				b3.push(b[i]);
				c3.push(c[i]);
				s3++;
			}
			ls=false;
		}
		haf2+=b[i];
	}
//	cout<<s2<<" "<<s3;
	for(int i=0; i<s2; i++) {
//		cout<<1<<endl;
		b4.push(b2.top());
		b2.pop();
		c4.push(c2.top());
		c2.pop();
	}
	long long left=0,right=0;
	for(int i=0; i<s2; i++) {
//		cout<<2<<endl;
//		cout<<"zong"<<c4.top()<<c3.top()<<endl;
		if(b4.top()==b3.top()) {
			if(c4.top()!=c3.top()) {
//				cout<<"why:"<<c4.top()<<c3.top()<<endl;
				left+=b3.top();
			}
			b3.pop();
			b4.pop();
			c3.pop();
			c4.pop();

//			cout<<"left"<<left<<endl;
			continue;
		}
		if(b4.top()>b3.top()) {
			i--;
			if(c3.top()!=c4.top()) {
				left+=b3.top();
			}
			long long t;
			t=b4.top();
			b4.pop();
			b4.push(t-b3.top());
			b3.pop();
			c3.pop();

//			cout<<"left"<<left<<endl;
			continue;
		}
		if(c3.top()!=c4.top()) {
			left+=b4.top();
		}
		long long t;
		t=b3.top();
		b3.pop();
		b3.push(t-b4.top());
		b4.pop();
		c4.pop();

//		cout<<"left"<<left<<endl;
		continue;
	}
	cout<<left;
}
