#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
int a[N][35];
int cnt[35];
int qpow(int a,int b){
	if(b==0)return 1;
	if(b==1)return a;
	int half=qpow(a,b/2);
	if(b%2==0)return half*half;
	return half*half*a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		int pos=1;
		while(num){
			a[i][pos]=num%2;
			cnt[pos]+=num%2;
			num/=2;
			pos++;
		}
	}
	int ans=0;
	int h=-1;
	set<int> s;
	for(int i=31;i>=1;i--){
		if(cnt[i]>=m&&h==-1){
			ans+=qpow(2,i-1); 
			h=i;
			for(int j=1;j<=n;j++){
				if(a[j][i]==1)s.insert(j);
			}
		}
		else if(cnt[i]>=m){
			int count=0;
			set<int> newset;
			for(int num:s){
				count+=a[num][i];
				if(a[num][i]==1)newset.insert(num);
			}
			if(count>=m){
				ans+=qpow(2,i-1);
				s=newset;
			}
		} 
	}
	cout<<ans;
}
