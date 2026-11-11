#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;
deque<int> q1;
deque<char> q2;
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t;
		char c;
		scanf("%d %c",&t,&c);
		q1.push_back(t);
		q2.push_back(c);
	}
	while(q1.size()>1){
		int numf=q1.front();q1.pop_front();
		int numb=q1.back();q1.pop_back();
		char charf=q2.front();q2.pop_front();
		char charb=q2.back();q2.pop_back();
		if(numf>numb){
			q1.push_front(numf-numb);
			q2.push_front(charf);
		}
		else if(numf<numb){
			q1.push_back(numb-numf);
			q2.push_back(charb);
		}
		if(charf!=charb) ans+=min(numf,numb);
	}
	printf("%lld",ans);
	return 0;
}
