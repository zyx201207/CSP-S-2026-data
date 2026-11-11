#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int a_;
	char b_;
};
aaa st[200020];
aaa ts[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	char b;
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		st[i].a_=a;
		st[i].b_=b;
		ts[i].a_=a;
		ts[n-i-1].b_=b;
		sum+=a;
	}
	long long x=0;
	for(int k=0;k<(sum/2);k++){
		int i=0;
		int j=0;
		if(st[i].b_!=ts[j].b_){
			x++;
		}
		st[i].a_--;
		st[i].a_--;
		if(st[i].a_<=0)i++;
		if(ts[j].a_<=0)j++;
	}
	cout<<x;
	return 0;
} 
