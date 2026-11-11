#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1,flag1=1,flag2=1,flag3=0;
const int N=2*1e5+10;
int a[N];
int q[4];
int mi[21];
int ji[21];
void dfs(int step,int sum,int num){
	if (num == m){
		ans=max(sum,ans);
		return;
	}
	if (step>n) return;
	for (int i=0;i<=1;i++){
		if (i == 0){
			dfs(step+1,sum,num);
		}
		else dfs(step+1,sum&a[step],num+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for (int i=0;i<=20;i++){
		mi[i]=pow(2,i);
	} 
	cin>>n>>m;
	for (int i=0;i<=20;i++){
		if (n == mi[i]){
			flag3=1;
			break;
		}
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i] != i-1) flag2=0;
		int flag=0;
		for (int i=0;i<=20;i++){
			if (mi[i]-1==a[i]) {
				ji[i]++;
				flag=1;
				break;
			}
		}
		if (flag==0) flag1=0;
	}
	if (n<=20){
		dfs(1,0x7fffffff,0);
		cout<<ans;
	}
	else if(m==n){
		int k=a[1];
		for (int i=2;i<=n;i++){
			k&a[i];
		}
		cout<<k;
	}
	else if (m == 1){
		cout<<*max_element(a+1,a+n+1);
	}
	else if (m == 2 && n<=2000){
		for (int i=1;i<n;i++){
			for (int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if (*max_element(a+1,a+n+1) < 4){
		for (int i=1;i<=n;i++){
			q[a[i]]++;
		}
		for (int i=3;i>=0;i--){
			if (m<=q[i]){
				cout<<i;
				break;
			}
			else m-=q[i];
		}
	}
	else if (flag3 && flag2){
		cout<<n-m;
	}
	else if (flag1){
		for (int i=20;i>=0;i++){
			if (ji[i]>=m){
				cout<<int(pow(2,i))-1;
				break;
			}
			else m-=ji[i];
		}
	}
	return 0;
} 
