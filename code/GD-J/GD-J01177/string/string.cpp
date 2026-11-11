#include<iostream>
#include<deque>
using namespace std;
struct Point{
	long long x;
	char a;
};
deque<Point>q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		Point f;
		cin>>f.x>>f.a;
		q.push_back(f);
	}
	long long ans=0;
	while(q.size()>1){
		Point f=q.front();q.pop_front();
		Point b=q.back();q.pop_back();
		if(f.a!=b.a){
			if(f.x>b.x){
				f.x-=b.x;
				q.push_front(f);
				ans+=b.x;
			}else if(f.x==b.x){
				ans+=f.x;
			}else{
				b.x-=f.x;
				q.push_back(b);
				ans+=f.x;
			}
		}else{
			if(f.x>b.x){
				f.x-=b.x;
				q.push_front(f);
			}else if(f.x<b.x){
				b.x-=f.x;
				q.push_back(b);
			}
		}
	}
	cout<<ans;
	return 0;
} 
