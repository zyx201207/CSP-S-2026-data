#include<bits/stdc++.h>
using namespace std;
long long cnt;
long long ans=0;
int kk;
int n;
long long num=0;
struct zu{
	long long shu;
	char val;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	vector<zu> chars(n+20);
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		num+=a;
		chars[i].val=c;
		chars[i].shu=a;
	}
	stack<zu> left;
	stack<zu> right;
	if(num%2==0){
		cnt=num/2;
		for(int i=1;i<=n;i++){
			if(chars[i].shu>=cnt){
				left.push({cnt,chars[i].val});
				kk=i;
				break;
			}else{
				left.push({chars[i].shu,chars[i].val});
				cnt-=chars[i].shu;
			}
		}
		for(int i=n;i>kk;i--){
			right.push({chars[i].shu,chars[i].val});
		}
		if(chars[kk].shu-cnt!=0){
			right.push({chars[kk].shu-cnt,chars[kk].val});
		}
	}else{
		cnt=num/2+1;
		for(int i=1;i<=n;i++){
			if(chars[i].shu>=cnt){
				if(cnt-1!=0){
					left.push({cnt-1,chars[i].val});
				}
				kk=i;
				break;
			}else{
				left.push({chars[i].shu,chars[i].val});
				cnt-=chars[i].shu;
			}
		}
		for(int i=n;i>kk;i--){
			right.push({chars[i].shu,chars[i].val});
		}
		if(chars[kk].shu-cnt!=0){
			right.push({chars[kk].shu-cnt,chars[kk].val});
		}
	}
	while(!left.empty()){
		zu A=left.top();
		zu B=right.top();
		left.pop();
		right.pop();
		if(A.shu>B.shu){
			if(A.val!=B.val){
				ans+=B.shu;
			}
			left.push({A.shu-B.shu,A.val});
		}else if(A.shu<B.shu){
			if(A.val!=B.val){
				ans+=A.shu;
			}
			right.push({B.shu-A.shu,B.val});
		}else if(A.shu==B.shu){
			if(A.val!=B.val){
				ans+=A.shu;
			}
		}
	}
	cout<<ans;
	return 0;
}//102min
