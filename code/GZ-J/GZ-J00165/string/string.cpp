//GZ-J00165 遵义市第四初级中学 聂宇东
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct str{
	ll a;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,c=0;
	cin>>n;
	deque<str> s;
	str q;
	for(int i=0;i<n;i++){
		cin>>q.a>>q.c;
		s.push_back(q);
	}
	int j=n-1;
	while(j>=1){
		if(s[0].a>s[j].a){
			q=s[0];
			s.pop_front();
			str q1;
			q1.a=s[--j].a;
			q1.c=q.c;
			q.a=q.a-q1.a;
			if(q1.c!=s[j].c)c+=q1.a;
			s.pop_back();
			s.push_front(q);
		}else if(s[0].a<s[j].a){
			q=s[j];
			s.pop_back();
			str q1;
			q1.a=s[0].a;
			q1.c=q.c;
			q.a=q.a-q1.a;
			if(q1.c!=s[0].c)c+=q1.a;
			j--;
			s.pop_front();
			s.push_back(q);
		}else{
			if(s[0].c!=s[j].c)c+=s[0].a;
			s.pop_front();
			s.pop_back();
			j-=2;
		}
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

