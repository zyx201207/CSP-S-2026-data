#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	long long a;
	char c;
}p[200005];
long long ans,fin;
stack<pair<long long,char> >k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i = 1;i<=n;i++){
		cin>>p[i].a>>p[i].c;
		ans+=p[i].a;
	}
	if(ans%2==0){
		long long mid = ans/2;
		long long cnt = 0;
		long long sum = 0;
		k.push({0,'a'});
		while(sum<mid){
			cnt++;
			sum+=p[cnt].a;
			k.push(make_pair(p[cnt].a,p[cnt].c));
		}
		if(sum>mid){
			k.pop();
			sum-=p[cnt].a;
			k.push(make_pair(mid-sum,p[cnt].c));
		}//1.让一半以前的数据进栈
		/*while(!k.empty()){
			cout<<k.top().first<<' '<<k.top().second<<endl;
			k.pop();
		}*/
		p[cnt].a = p[cnt].a-(mid-sum);
		long long len = k.top().first;
		char op = k.top().second;
		k.pop();
		while(k.size()>0){
			if(p[cnt].a>len){
				if(p[cnt].c!=op){
					fin += len;
				}
				p[cnt].a=p[cnt].a-len;
				len = k.top().first;
				op = k.top().second;
			}else if(p[cnt].a<len){
				if(p[cnt].c!=op){
					fin+=p[cnt].a;
				}
				len=len-p[cnt].a;
				cnt++;
			}else{
				if(p[cnt].c!=op){
					fin+=len;
				}
				cnt++;
				len = k.top().first;
				op = k.top().second;
				k.pop();
			}
		}
		cout<<fin;
	}else{
		long long mid = ans/2+1;
		long long cnt = 0;
		long long sum = 0;
		k.push({0,'a'});
		while(sum<mid){
			cnt++;
			sum+=p[cnt].a;
			k.push(make_pair(p[cnt].a,p[cnt].c));
		}
		if(sum>mid){
			k.pop();
			sum-=p[cnt].a;
			k.push(make_pair(mid-sum-1,p[cnt].c));
		}//1.让一半以前的数据进栈
		/*while(!k.empty()){
			cout<<k.top().first<<' '<<k.top().second<<endl;
			k.pop();
		}*/
		p[cnt].a = p[cnt].a-(mid-sum);
		long long len = k.top().first;
		char op = k.top().second;
		k.pop();
		while(k.size()>0){
			if(p[cnt].a>len){
				if(p[cnt].c!=op){
					fin += len;
				}
				p[cnt].a=p[cnt].a-len;
				len = k.top().first;
				op = k.top().second;
			}else if(p[cnt].a<len){
				if(p[cnt].c!=op){
					fin+=p[cnt].a;
				}
				len=len-p[cnt].a;
				cnt++;
			}else{
				if(p[cnt].c!=op){
					fin+=len;
				}
				cnt++;
				len = k.top().first;
				op = k.top().second;
				k.pop();
			}
		}
		cout<<fin;
	}
	return 0;
}
