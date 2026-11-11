#include <bits/stdc++.h>
using namespace std;

const int N=2*1000*100+10;

long long a[N];
long long b[N];
long long pre[40];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	pre[0]=1;
	pre[1]=2;
	for (int i=2;i<=30;i++){
		pre[i]=pre[i-1]*2;
//		cout <<pre[i]<<' '; 
	}
	
	int n,m;
	
	cin >>n>>m;
	

	for (int i=1;i<=n;i++){
		cin >>a[i];
	}
	
	int len=n,cnt=0;//a数组长度，当前位可选出的数 
	long long ans=0;
	for (int i=30;i>=0;i--){
		for (int j=1;j<=len;j++){
	
			if (a[j]>=pre[i])b[++cnt]=a[j]-pre[i];
			
		}
		
		if (cnt>=m){//能选出 
//			cout <<1<<' '<<cnt<<endl;
			ans+=pre[i];
		
			for (int j=1;j<=cnt;j++)a[j]=b[j];
			len=cnt;
			cnt=0;//清空b数组 
		}
		else cnt=0;//清空b数组 
		
//		cout <<ans<<' ';
	}
	
	cout <<ans;
	
	
	return 0;
}
