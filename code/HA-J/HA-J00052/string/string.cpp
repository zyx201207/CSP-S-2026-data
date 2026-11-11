#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e5+10;
//silu:shuangzhizhenbianli
//yudaobutongjiu cnt++
ll n,tot,cnt; // tot:zongchang
struct node{
	int num;
	char c;
} a[MAXN];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		//tot+=a[i].num;
		cin>>a[i].c;
	}
	ll l=0,r=n;
	//cout<<tot;
	while(l<r){
		if(a[l].c==a[r].c){//zifuyiyang buyonggeng gai
			if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				l++;
			}else if(a[l].num==a[r].num){
				l++;
				r--;
			}else{
				a[l].num-=a[r].num;
				r--;
			}
		}
		else{
			if(a[l].num<a[r].num){
				cnt+=a[l].num;
				a[r].num-=a[l].num;
				if(a[r].num==0) r--;
				l++;
			}else if(a[l].num==a[r].num){
				cnt+=a[l].num;
				l++;
				r--;
			}else{
				cnt+=a[r].num;
				a[l].num-=a[r].num;
				if(a[l].num==0) l++;
				r--;
			}
		}
		//cout<<l<<' '<<r<<' '<<a[l].num<<a[l].c<<' '<<a[r].num<<a[r].c<<' '<<cnt<<endl;
	}
	cout<<cnt;
	return 0;
}
