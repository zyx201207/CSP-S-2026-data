#include<bits/stdc++.h>
using namespace std;
struct s{
	int c;
	char ch;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	queue<s> q1,q2;
	s str[20001],rts[20001];
	int a,b;
	char c;
	long long n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		str[i].c=a;
		str[i].ch=c;
		q1.push(str[i]);
	}
	for(int i=n;i>=1;i--){
		rts[i].c=str[i].c;
		rts[i].ch=str[i].ch;
		q2.push(rts[i]);
	}
	s Q1=q1.front(),Q2=q2.front();
	while(!(q1.empty()||q2.empty())){
		if(Q1.c==0){
			q1.pop();
			Q1=q1.front();
		}
		if(Q2.c==0){
			q2.pop();
			Q2=q2.front();
		}
		if(Q1.c>Q2.c){
			if(Q1.ch!=Q2.ch){
				cnt+=Q2.c;
			}
			Q1.c-=Q2.c;
			Q2.c=0;
		}
		else{
			if(Q1.ch!=Q2.ch){
				cnt+=Q1.c;
			}
			Q2.c-=Q1.c;
			Q1.c=0;
		}
		if(q1.empty()||q2.empty()){
			cnt+=max(Q1.c,Q2.c);
		}
	}
	cout<<cnt/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
