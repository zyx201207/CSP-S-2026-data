#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct str{
	int a;
	char c;
};
queue<str> q1,q2;
str s[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int l;
	long long ans=0;
	cin>>l;
	for(int i=1;i<=l;i++){
		cin>>s[i].a>>s[i].c;
	}
	for(int left=1,right=l;left<=right;){
		if(q1.empty()){
			q1.push(s[left]);
			left++;
		}
		if(q2.empty()){
			q2.push(s[right]);
			right--;
		}
		while(!q1.empty()&&!q2.empty()){
			if(q1.front().c!=q2.front().c){
				int t=min(q1.front().a,q2.front().a);
				q1.front().a-=t;
				q2.front().a-=t;
				ans+=t;
			}else{
				int t=min(q1.front().a,q2.front().a);
				q1.front().a-=t;
				q2.front().a-=t;
			}
			if(q2.front().a==0){
				q2.pop();
			}
			if(q1.front().a==0){
				q1.pop();
			}
		}
	}
	cout<<ans;
	return 0;
} 
