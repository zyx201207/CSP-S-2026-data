#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],num,num2,cnt,ans;
char c[N];
struct node{
	char s;
	int len;
};
stack<node> q1;
queue<node> q2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	num2=num;
	num=(num+1)/2;
	for(int i=1;i<=n;i++){
		if(cnt+a[i]<=num){
			cnt+=a[i];
			q1.push((node){c[i],a[i]});
		}
		else if(cnt<num&&cnt+a[i]>num){
			q1.push((node){c[i],num-cnt});
			q2.push((node){c[i],cnt+a[i]-num});
			cnt=num;
		} 
		else{
			q2.push((node){c[i],a[i]});
		}
	}
	if(num2&1){
		if(q1.top().len==0) q1.pop();
		q1.top().len--;
		if(q1.top().len==0) q1.pop();
	}
	int res=0;
	while(!q1.empty()){
		res+=q1.top().len;
		char now=q1.top().s;
		q1.pop();
		while(res-q2.front().len>=0&&!q2.empty()){
			res-=q2.front().len;
			if(q2.front().s!=now){
				ans+=q2.front().len;
			}
			q2.pop();
		}
		if(res>0&&res-q2.front().len<0){
			q2.front().len-=res;
			if(q2.front().s!=now){
				ans+=res;
			}
			res=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
