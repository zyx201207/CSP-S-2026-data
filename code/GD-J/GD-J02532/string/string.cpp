#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+10;
int n;
ll a[maxn];
char ch[maxn];
//思路：模拟字符串从首尾向中间对比，若不满足回文，则ans++ 
void solve1(){//maxa<=500,暴力模拟 
	string s="";
	for(int i=1;i<=n;i++){//拼接字符串 
		for(int j=1;j<=a[i];j++){
			s+=ch[i];
		}
	}
	ll ans=0,lens=s.size();
	for(int i=0;i<(lens+1)/2;i++){
		if(s[i]!=s[lens-1-i]){//是否满足回文 
			ans++;
		}
	}
	cout<<ans;
}
void solve2(){//maxa<=1e9,按段模拟
	ll ans=0;
	int i=1,j=n;
	while(i!=j&&i<j){//双指针遍历段 (一定要注意清空顺序！)
		if(ch[i]==ch[j]){
			if(a[i]==a[j]){
				a[i]=0,a[j]=0;
				i++,j--;
			}
			else if(a[i]>a[j]){
				a[i]-=a[j],a[j]=0;
				j--;
			}
			else{
				a[j]-=a[i],a[i]=0;
				i++;
			}
		}
		else{
			if(a[i]==a[j]){
				ans+=a[i];
				a[i]=0,a[j]=0;
				i++,j--;
			}
			else if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j],a[j]=0;
				j--;
			}
			else{
				ans+=a[i];
				a[j]-=a[i],a[i]=0;
				i++;
			}
		}
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll maxa=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		maxa=max(maxa,a[i]);
	}
	if(n<=1){
		cout<<0;
	}
	else if(maxa<=500){
		solve1();
	}
	else{
		solve2(); 
	}
	return 0;
}
