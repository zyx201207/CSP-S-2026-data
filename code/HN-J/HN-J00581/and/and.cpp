#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
const ll inf=2147483647;
ll n,m,a[N],sum=-1;
ll maxa=-1,f1=1,f2=1;
bool Special_A(int k){
	int t=log2(k+1);
	if(pow(2,t)==k+1){
		return 1;
	}
	else{
		return 0;
	}
}
void dfs(int len,int index,ll cnt){
	if(cnt==0){
		return;
	}
	if(len==m){
		sum=max(sum,cnt);
		return;
	}
	for(int i=index+1;i<=n;i++){
		dfs(len+1,i,cnt&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int x=log2(n);
	if(pow(2,x)!=n){
		f2=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]); 
		if(a[i]!=i-1){
			f2=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(Special_A(a[i])==0){
			f1=0;
			break;
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			sum=max(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}
	else if(m==n){
		int k=a[1];
		for(int i=2;i<=n;i++){
			k&=a[i];
		}
		cout<<k;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout<<sum;
		return 0;
	}
	else if(n<=20){
		dfs(0,0,inf);
		cout<<sum;
		return 0;
	}
	else if(maxa<4){
		int tong[5]={};
		for(int i=1;i<=n;i++){
			tong[a[i]]++;
		}
		if(tong[3]>=m){
			cout<<"3";
			return 0;
		}
		else{
			m-=tong[3];
			if(tong[2]>=m){
				cout<<"2";
				return 0;
			}
			else if(tong[1]>=m){
				cout<<"1";
				return 0;
			}
			else{
				cout<<"0";
				return 0;
			}
		}
	}
	else if(f1==1){
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		cout<<a[m];
		return 0;
	}
	else if(f2==1){
		if(m>(n/2)){
			cout<<"0";
			return 0;
		}
		int n1=n-m;
		int b[N]={},in=-1;
		while(n1>0){
			in++;
			b[in]=n1%2;
			n1/=2;
		}
		sum=0;
		for(int i=in;i>=0;i--){
			if(b[i]==1){
				sum+=pow(2,in);
			}
			else{
				break;
			}
		}
		cout<<sum;
		return 0;
	}
	return 0;
} 
