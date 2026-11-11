#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct str{
	char c;
	int len;
}a[N];
stack<str>st1,st2;
int ans=0,n,sum;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		sum+=a[i].len;
	}
	sum/=2;
	for(int i=1,sum1=0;i<=n;i++){
		if(sum1+a[i].len>sum){
			str o;
			o.c=a[i].c;
			o.len=sum-sum1;
			if(o.len)st1.push(o);
			break;
		}
		else{
			st1.push(a[i]);
			sum1+=a[i].len;
		}
	}
	for(int i=n,sum2=0;n>=1;i--){
		if(sum2+a[i].len>sum){
			str o;
			o.c=a[i].c;
			o.len=sum-sum2;
			if(o.len)st2.push(o);
			break;
		}
		else{
			st2.push(a[i]);
			sum2+=a[i].len;
		}
	}
	/*while(!st1.empty()){
		cout<<st1.top().c<<' '<<st1.top().len<<' ';
		st1.pop();
	}cout<<endl;
	while(!st2.empty()){
		cout<<st2.top().c<<' '<<st2.top().len<<' ';
		st2.pop();
	}cout<<endl;*/
	while(!st1.empty()){
		str o1=st1.top(),o2=st2.top();
		st1.pop();st2.pop();
		if(o1.c==o2.c){
			if(o1.len>o2.len){
				o1.len-=o2.len;
				st1.push(o1);
			}
			else if(o1.len<o2.len){
				o2.len-=o1.len;
				st2.push(o2);
			}
		}
		else{
			if(o1.len>o2.len){
				o1.len-=o2.len;
				ans+=o2.len;
				st1.push(o1);
			}
			else if(o1.len<o2.len){
				o2.len-=o1.len;
				ans+=o1.len;
				st2.push(o2);
			}
			else{
				ans+=o1.len;
			}
		}
	}cout<<ans;
	return 0;
}
