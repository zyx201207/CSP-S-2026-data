#include<iostream>
#include<deque>
using namespace std;

struct Str{
	int num;
	char c;
};

long long n,ans;
string s;
deque<Str> dq;

void debug(){
	int len=(int)dq.size();
	for(int i=1;i<=len;i++){
		Str tmp=dq.front();
		cout<<tmp.num<<tmp.c<<" ";
		dq.pop_front();
		dq.push_back(tmp);
	}
	cout<<endl; 
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		dq.push_back({x,c});
	}
//	debug();
	
	while(!dq.empty()){
		if(dq.size()==1){
			break;
		}
		Str head=dq.front(),tail=dq.back();
//		printf("拿出front:%d%c  back%d%c\n",head.num,head.c,tail.num,tail.c);
		dq.pop_back(),dq.pop_front();
		if(head.num==tail.num){
			if(head.c!=tail.c){
				ans+=head.num;
//				printf("答案增加 %d\n",ans);
			}
		}else if(head.num>tail.num){
			Str tmp;
			tmp.num=head.num-tail.num;
			tmp.c=head.c;
			if(head.c!=tail.c){
				ans+=tail.num;
//				printf("答案增加 %d\n",tail.num);
			}
			dq.push_front(tmp);
//			printf("放回 %d%c\n",tmp.num,tmp.c);
		}else{
			Str tmp;
			tmp.num=tail.num-head.num;
			tmp.c=tail.c;
			if(head.c!=tail.c){
				ans+=head.num;
//				printf("答案增加 %d\n",head.num);
			}
			dq.push_back(tmp);
//			printf("放回 %d%c\n",tmp.num,tmp.c);
		}
//		printf("此时deque\n");
//		debug();
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
