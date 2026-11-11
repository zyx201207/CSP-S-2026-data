#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
struct st{
	int num=0;
	char zm;
}str[200005],x,y,nw;
stack<st> zh,fan;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&str[i].num);
		cin>>str[i].zm;
		fan.push(str[i]);
	}
	for(int i=n;i>=1;i--)
		zh.push(str[i]);
	while(!zh.empty()){
		x=zh.top();
		y=fan.top();
		zh.pop();
		fan.pop();
		if(x.zm==y.zm&&x.num==y.num){
			continue;
		}
		if(x.zm==y.zm){
			if(x.num>y.num){
				nw.num=x.num-y.num;
				nw.zm=x.zm;
				zh.push(nw);
			}
			else {
				nw.num=y.num-x.num;
				nw.zm=y.zm;
				fan.push(nw);
			}
			continue;
		}
		if(x.num==y.num){
			ans+=x.num;
			continue;
		}
		if(x.num>y.num){
			ans+=y.num;
			nw.num=x.num-y.num;
			nw.zm=x.zm;
			zh.push(nw);
			continue;
		}
		if(x.num<y.num){
			ans+=x.num;
			nw.num=y.num-x.num;
			nw.zm=y.zm;
			fan.push(nw);
			continue;
		}
	}
	cout<<ans/2;	
	return 0;
} 
