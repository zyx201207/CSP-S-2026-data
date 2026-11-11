#include<bits/stdc++.h>
//#define int long long
using namespace std;
int a[200001];
queue<int>q;
queue<int>q1;
signed main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		q.push(t);
//		string s1='0';
//		while(t){
//			char p='0'+t%2;
//			s1+=p;
//			t/=2;
//		}
//		int k=0;
//		for(int j=s1.size()-1;j>=0;j--){
//			++k;
//			s[i]+=s1[j];
//			if(s1[j]-'0') js[k]++,bj[k]+=(i+'0'); 
//		}
//		maxn=max(maxn,k); 
	}
	for(int i=30;i>=1;i--){
		int ans=0;
		while(!q.empty()){
			if(q.front()>=int(pow(2,i))) ans++;
			q1.push(q.front());
			q.pop();
		}
		if(ans>=m){
			while(!q1.empty()){
				if(q1.front()>=int(pow(2,i))){
					q.push(q1.front());
				}
				q1.pop();
			}
		}
		else{
			while(!q1.empty()){
				q.push(q1.front());
				q1.pop();
			}
		}
	}
	int k=1;
	while(!q.empty()) a[++k]=q.front(),q.pop();
	sort(a+1,a+1+k);
	int ans=a[k];
	for(int i=k-1;i>=k-m+1;i--) ans&=a[i];
	cout<<ans;
    return 0;
}
/*
首先，并不能贪心。
所以用位数思想，做进一步贪心 
*/
