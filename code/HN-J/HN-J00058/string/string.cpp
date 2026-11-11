#include<bits/stdc++.h>
using namespace std;
struct s{
	int num;
	char data;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<s> str;
	long long strsize = 0;
	int n=0;
	cin>>n;
	while(n--){
		long long t=0;
		cin>>t;
		char c;
		cin>>c;
		s news;
		news.data = c;
		news.num = t;
		str.push_back(news);
		strsize += t;
	}
	long long mid=(strsize>>1);
	s *l,*r;
	r=&str[str.size()-1];
	l=&str[0];
	long ri=str.size()-1;
	long li=0;
	long long space=mid;
	long long count=0;
	while(space){
		if(l->num > r->num){
			if(l->data != r->data) count+=r->num;
			l->num-=r->num;
			space-=r->num;
			r->num=0;
			r=&str[ri--];
		}else if(l->num = r->num){
			if(l->data != r->data) count+=r->num;
			l->num=0;
			space-=r->num;
			r->num=0;
			r=&str[ri--];
			l=&str[li++];
		}else{
			if(l->data != r->data) count+=r->num;
			r->num-=l->num;
			space-=l->num;
			if(r->data != l->data) count+=l->num;
			l->num=0;
			l=&str[li++];
		}
	}

	cout<<count;
	return 0;
} 
